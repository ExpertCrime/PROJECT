
# AutoSub

This Python script automates the process of transcribing a video file and encoding subtitles. It transcribes audio from the video and creates subtitle files, making it easier to add subtitles to your video content

---

## **Who This Might Help**

This tool is designed to help individuals and teams who need to quickly transcribe and subtitle videos. It can be particularly useful for:

- **Transcriptionists**: Easily convert audio from videos into text for transcribing purposes.
- **Content Creators**: Add subtitles to videos for better accessibility and engagement.
- **Video Editors**: Streamline the process of subtitle creation and embedding for video projects.
- **Educators**: Generate subtitles for educational videos or lectures.
- **Social Media Managers**: Add subtitles to videos for sharing on platforms like YouTube, Instagram, or TikTok.
- **Accessibility Advocates**: Ensure videos are accessible to the hearing impaired by adding accurate subtitles.

---# Video Transcription and Subtitle Encoder

## **System Requirements**

- **Operating System:**  
  Windows

- **Minimum RAM:**  
  4 GB

- **Processor:**  
  Intel i3 or equivalent

---

## **Software Requirements**

1. **FFmpeg**  
   Required for handling video and audio processing.

2. **Python**  
   Ensure Python is installed (preferably version 3.7 or higher).

3. **Pip**  
   Python's package installer (usually comes with Python).

4. **Whisper (OpenAI)**
   Used for transcribing audio from various audio files or video files.
---

> **Note:** Make sure all the software dependencies are properly installed before running the script.

---

## 🚨 **Important Note** 🚨

> **⚠️ Attention:**  
> If your system has lower specifications (e.g., lower RAM or an older processor), it is **recommended** to choose a **smaller model** in Whisper.  
> Using a larger model may cause **performance issues** or **errors** on lower-end systems. ⚡️

---

---

## **Pros of This Program**

- **Automated Workflow**:  
  The entire process—from transcription to subtitle embedding—is automated, saving time and effort.

- **Supports Multiple Subtitle Embedding Options**:  
  Users can choose between **soft** and **hard** embedding of subtitles, giving flexibility depending on the use case.

- **Open-Source and Easy to Use**:  
  The script is written in Python and relies on popular libraries like **Whisper** and **FFmpeg**, making it easy for developers to adapt and customize.

- **Enhanced Accessibility**:  
  Automatically adds subtitles to videos, making them accessible to a wider audience, including the hearing impaired.

- **Fast Transcription with Whisper**:  
  Leverages the **Whisper** model from OpenAI for high-quality audio-to-text transcription, ensuring accurate results.

- **Customizable for Low-End Systems**:  
  The program allows users with lower-spec systems to choose smaller models to avoid performance issues, ensuring a wider compatibility.

- **Supports Popular Video Formats**:  
  Works with a variety of video formats, ensuring versatility for different types of media.

- **Efficient Video Processing**:  
  Utilizes **FFmpeg**, a powerful tool for video processing, ensuring smooth and fast video and subtitle embedding.

- **Free and Open-Source**:  
  Being open-source, this tool is free to use and can be modified or extended to suit specific needs.

---

# Roadmap of the Process

This project automates the process of transcribing video content, creating subtitles, and embedding those subtitles into the video. Below is a detailed roadmap of the entire process:

---

## **Process Overview**

1. **Convert Video to Audio**  
   - The program uses **Whisper** to extract audio from the video file.

2. **Transcribe Audio to Subtitles**  
   - The audio is then transcribed into subtitles using **Whisper**.

3. **Embed Subtitles into Video**  
   - The program prompts the user to choose the type of subtitle embedding:
     - **Soft Embedding** (subtitles are stored as a separate file and displayed during playback)
     - **Hard Embedding** (subtitles are permanently embedded into the video)
   - Depending on the choice, the program uses **FFmpeg** to embed the subtitles.

4. **Generate Output File**  
   - After embedding the subtitles, the program creates the final output video file with the selected subtitle embedding.

---

## **Visual Workflow:**

```plaintext
[Video File] 
     |
     v
[Whisper: Convert Video to Audio]  
     |
     v
[Whisper: Transcribe Audio to Subtitles] 
     |
     v
[Choose Embedding Type: Soft or Hard] 
     |
     v
[FFmpeg: Embed Subtitles] 
     |
     v
[Output Video File with Subtitles]

