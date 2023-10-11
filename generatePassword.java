import java.util.Random;

public class PasswordGenerator {

    private static final String SPECIAL_CHARACTERS = "!@#$%^&*()_-+={}[]|;:'<>,.?/`~";
    private static final String NUMERIC_CHARACTERS = "0123456789";
    private static final String UPPERCASE_CHARACTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    private static final String LOWERCASE_CHARACTERS = "abcdefghijklmnopqrstuvwxyz";

    public static String generatePassword(int length) {
        Random random = new Random();

        StringBuilder password = new StringBuilder();
        for (int i = 0; i < length; i++) {
            int characterType = random.nextInt(4); // 0 = special, 1 = numeric, 2 = uppercase, 3 = lowercase
            switch (characterType) {
                case 0:
                    password.append(SPECIAL_CHARACTERS.charAt(random.nextInt(SPECIAL_CHARACTERS.length())));
                    break;
                case 1:
                    password.append(NUMERIC_CHARACTERS.charAt(random.nextInt(NUMERIC_CHARACTERS.length())));
                    break;
                case 2:
                    password.append(UPPERCASE_CHARACTERS.charAt(random.nextInt(UPPERCASE_CHARACTERS.length())));
                    break;
                case 3:
                    password.append(LOWERCASE_CHARACTERS.charAt(random.nextInt(LOWERCASE_CHARACTERS.length())));
                    break;
            }
        }

        return password.toString();
    }

    public static void main(String[] args) {
        int passwordLength = 8;
        String password = generatePassword(passwordLength);

        System.out.println("Generated password: " + password);
    }
}
