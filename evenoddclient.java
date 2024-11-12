import java.io.*;
import java.net.*;
import java.util.Scanner;
public class evenoddclient{
public static void main(String[] args){
String hostname="localhost";
int port=12345;
try(Socket socket=new Socket(hostname,port)){
System.out.print("Connected to server:");
DataInputStream input=new DataInputStream(socket.getInputStream());
DataOutputStream output=new DataOutputStream(socket.getOutputStream());
Scanner Scanner=new Scanner(System.in);
System.out.println("Enter a number:");
int numberToSend=Scanner.nextInt();
System.out.println("Sending number:"+numberToSend);
output.writeInt(numberToSend);
String result=input.readUTF();
System.out.println("Received result:"+result);
}
catch(IOException e){
System.out.println("Client error:"+e.getMessage());
}
}
}
