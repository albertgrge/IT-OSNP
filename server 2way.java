import java.net.*;
import java.io.*;
public class server{
public static void main(String[]args) throws Exception,UnknownHostException{
ServerSocket ss=new ServerSocket(8088);
Socket s =ss.accept();
DataInputStream din=new DataInputStream(s.getInputStream());
DataOutputStream dout=new DataOutputStream(s.getOutputStream());
BufferedReader br=new  BufferedReader(new InputStreamReader(System.in));
String str="",str2="";
while(str!="stop")
{
System.out.println("Waiting for clients reply....");
str=din.readUTF();
System.out.println("Client:"+str);
System.out.println("Enter message:");
str2=br.readLine();
dout.writeUTF(str2);
dout.flush();
}
din.close();
s.close();
ss.close();
}
}
