import java.io.*;
import java.net.*;
class evenoddserver{
public static void main(String []args){
int port=12345;
try(ServerSocket ServerSocket=new ServerSocket(port)){
System.out.println("Server is listening on port:"+port);
while(true){
try(Socket socket=ServerSocket.accept()){
System.out.println("Client connected:");
DataInputStream input=new DataInputStream(socket.getInputStream());
DataOutputStream output=new DataOutputStream(socket.getOutputStream());
int number=input.readInt();
System.out.println("Received number:"+number);
String result=(number%2==0)?"Even":"Odd";
output.writeUTF(result);
System.out.println("Sent result:"+result);
}
catch(IOException e){
System.out.print("Client error:"+e.getMessage());
}
}
}
catch(IOException e){
System.out.print("Server error:"+e.getMessage());
}
}
}

