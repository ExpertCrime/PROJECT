import java.security.SecureRandom;

public class PasswordGenerator {

    public static void main(String[] args) {
        int length = 12; // Password length
        String password = generatePassword(length);
        System.out.println("Generated Password: " + password);
    }

    private static String generatePassword(int length) {
        String lowercase = "abcdefghijklmnopqrstuvwxyz";
        String uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String numbers = "0123456789";
        String symbols = "+-*/=!@#$%^&*()";

        String allCharacters = lowercase + uppercase + numbers + symbols;

        SecureRandom random = new SecureRandom();
        StringBuilder password = new StringBuilder();

        for (int i = 0; i < length; i++) {
            int randomIndex = random.nextInt(allCharacters.length());
            password.append(allCharacters.charAt(randomIndex));
        }

        return password.toString();
    }
}
