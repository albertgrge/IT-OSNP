import java.io.*;
import java.net.*;

public class chatserver {
    public static void main(String[] args) throws IOException {
        ServerSocket serverSocket = new ServerSocket(8008);
        System.out.println("Server listening to client");

        while (true) {
            Socket socket = serverSocket.accept();
            System.out.println("Client connected :)");

            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

            String text = in.readLine();
            if (text == null) {
                break;
            }

            String[] words = text.split("\\s+");
            int wordCount = words.length;
            int blankSpaceCount = wordCount - 1;
            int sentenceCount = countSentences(text);
		int wordss=wordCount+sentenceCount-1;
            out.println("Number of words: " + wordss+"\nNumber of blank spaces: "+blankSpaceCount+"\nNumber of sentences: "+sentenceCount);
 

            socket.close();
        }

        serverSocket.close();
    }

    private static int countSentences(String text) {
        int count = 0;
        for (int i = 0; i < text.length(); i++) {
            char c = text.charAt(i);
            if (c == '.' || c == '?' || c == '!') {
                count++;
            }
        }
        return count;
    }
}
