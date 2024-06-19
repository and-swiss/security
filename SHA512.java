 import java.math.BigInteger;
 import java.security.MessageDigest;
 import java.security.NoSuchAlgorithmException;
 import java.util.Scanner;
 public class SHA512Hash {
 // Method to calculate SHA-512 hash value
 public static String encryptThisString(String input) {
 try {
 // getInstance() method is called with algorithm SHA-512
 MessageDigest md = MessageDigest.getInstance("SHA-512");
 // digest() method is called to calculate message digest of the input string
 // returned as array of byte
 byte[] messageDigest = md.digest(input.getBytes());
 // Convert byte array into signum representation
 BigInteger no = new BigInteger(1, messageDigest);
 // Convert message digest into hex value
 String hashtext = no.toString(16);
 // Add preceding 0s to make it 128 bit (SHA-512 hash is 512 bits or 64 bytes, thus
 128 hex characters)
 while (hashtext.length() < 128) {
 hashtext = "0" + hashtext;
 }
// Return the HashText
 return hashtext;
 }
 // For specifying wrong message digest algorithms
 catch (NoSuchAlgorithmException e) {
 throw new RuntimeException(e);
 }
 }
 // Main method to take user input and display the SHA-512 hash
 public static void main(String args[]) throws NoSuchAlgorithmException {
 Scanner sc = new Scanner(System.in);
 System.out.println("Enter the string to hash using SHA-512:");
 String input = sc.nextLine();
 System.out.println("HashCode Generated by SHA-512 for: " + input);
 System.out.println("\n" + input + " : " + encryptThisString(input));
 }
 }
