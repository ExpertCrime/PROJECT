import os
import subprocess
import sys
import time
import socket

def check_internet_connection():
    print("\nChecking Internet connection...")
    while True:
        try:
            socket.create_connection(("8.8.8.8", 53), timeout=3)
            print("Internet connection: Available\n")
            break
        except OSError:
            print("No Internet connection. Please connect to Wi-Fi or Ethernet...")
            time.sleep(5)

def check_dependency(command, name):
    try:
        result = subprocess.run(command, capture_output=True, text=True, shell=True)
        if result.returncode == 0:
            print(f"{name} - Installed")
            return True
    except Exception as e:
        print(f"{name} - Not Installed. Error: {e}")
    return False

def install_dependency(command, name):
    print(f"\nInstalling {name}...")
    try:
        subprocess.run(command, shell=True, check=True)
        print(f"{name} installed successfully.")
        return True
    except subprocess.CalledProcessError as e:
        print(f"Failed to install {name}. Error: {e}")
        return False

def extract_audio(video_path, audio_path):
    print("\nExtracting audio from video...")
    cmd = f'ffmpeg -i "{video_path}" -q:a 0 -map a "{audio_path}" -y'
    subprocess.run(cmd, shell=True, check=True)
    print("Audio extraction complete.\n")

def transcribe_audio(audio_path, output_srt_path, language='Hindi', model='small'):
    print("\nStarting transcription (this may take time)...")
    output_dir = os.path.dirname(output_srt_path)
    cmd = f'whisper "{audio_path}" --language {language} --task transcribe --device cpu '\
          f'--model {model} --fp16 False --output_format srt --output_dir "{output_dir}"'
    subprocess.run(cmd, shell=True, check=True)

    # Locate the generated .srt file
    base_audio_name = os.path.splitext(os.path.basename(audio_path))[0]
    if base_audio_name.endswith("_audio"):
        generated_srt_path = os.path.join(output_dir, f"{base_audio_name}.srt")
    else:
        generated_srt_path = os.path.join(output_dir, f"{base_audio_name}_audio.srt")

    if os.path.isfile(generated_srt_path):
        # Rename the generated file to match the expected format
        os.rename(generated_srt_path, output_srt_path)
        print(f"Subtitle file renamed to: {output_srt_path}")
    else:
        print(f"Error: Expected subtitle file not found at {generated_srt_path}.")
        sys.exit(1)

    print("Transcription complete.\n")

def encode_subtitles(video_path, srt_path, output_dir, mode):
    filename = os.path.splitext(os.path.basename(video_path))[0]
    output_path = os.path.join(output_dir, f"{filename}_subtitled.mp4")
    
    if mode == '1':
        # Soft subtitle (muxing without re-encoding)
        print("\nEncoding soft subtitles (separate track)...")
        cmd = f'ffmpeg -i "{video_path}" -i "{srt_path}" -c:v copy -c:a copy -c:s mov_text "{output_path}" -y'
    elif mode == '2':
        # Hard subtitle (burning into video)
        print("\nEncoding hard subtitles (burning into video)...")
        cmd = f'ffmpeg -i "{video_path}" -vf subtitles="{srt_path}" "{output_path}" -y'
    else:
        print("Invalid subtitle encoding choice.")
        sys.exit(1)

    subprocess.run(cmd, shell=True, check=True)
    print(f"Video with subtitles saved at: {output_path}\n")

def main():
    print("="*50)
    print("  VIDEO TRANSCRIPTION AND SUBTITLE ENCODER  ")
    print("="*50)

    # Step 1: Check Internet
    check_internet_connection()

    # Step 2: Dependency check
    print("Checking system dependencies...\n")
    dependencies = {
        "Python": ("python --version", None),
        "pip": ("pip --version", None),
        "ffmpeg": ("ffmpeg -version", "choco install ffmpeg -y"),
        "whisper": ("whisper --help", None)  # Skip installation for whisper
    }

    for name, (check_cmd, install_cmd) in dependencies.items():
        installed = check_dependency(check_cmd, name)
        if not installed and install_cmd:
            install_dependency(install_cmd, name)
    
    # Step 3: Input paths
    video_path = input("\nEnter full path to input video file: ").strip('"')
    while not os.path.isfile(video_path):
        print("Invalid video path. Please try again.")
        video_path = input("Enter full path to input video file: ").strip('"')

    output_dir = input("Enter full path to output directory: ").strip('"')
    if not os.path.isdir(output_dir):
        os.makedirs(output_dir, exist_ok=True)

    # Paths
    filename = os.path.splitext(os.path.basename(video_path))[0]
    audio_path = os.path.join(output_dir, f"{filename}_audio.mp3")
    output_srt_path = os.path.join(output_dir, f"{filename}.srt")

    # Step 4: Language Selection
    print("\nSelect language for transcription:")
    print("1 - Hindi (Default)")
    print("2 - English")
    print("3 - Other")
    lang_choice = input("Enter your choice (1/2/3): ").strip()
    
    language = 'Hindi'  # default
    if lang_choice == '2':
        language = 'English'
    elif lang_choice == '3':
        language = input("Enter language name: ").strip()

    # Step 5: Model Selection
    print("\nSelect Whisper model:")
    print("1 - small (Default, faster)")
    print("2 - medium (More accurate)")
    print("3 - large (Most accurate but slower)")
    model_choice = input("Enter your choice (1/2/3): ").strip()
    
    model = 'small'  # default
    if model_choice == '2':
        model = 'medium'
    elif model_choice == '3':
        model = 'large'

    # Step 6: Process
    extract_audio(video_path, audio_path)
    transcribe_audio(audio_path, output_srt_path, language=language, model=model)

    # Step 7: Validate Subtitle File
    if not os.path.isfile(output_srt_path):
        print(f"Error: Subtitle file not found at {output_srt_path}. Transcription may have failed.")
        sys.exit(1)

    # Step 8: Subtitle Encoding
    print("Choose subtitle encoding option:")
    print("1 - Soft Subtitle (separate subtitle track)")
    print("2 - Hard Subtitle (burn subtitles into video)")
    choice = input("Enter your choice (1/2): ").strip()

    encode_subtitles(video_path, output_srt_path, output_dir, choice)

    # Step 9: Summary
    print("="*50)
    print(" Process Complete! ")
    print("="*50)

if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\nProcess interrupted by user. Exiting.")
        sys.exit(0)
