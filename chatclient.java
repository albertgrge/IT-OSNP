import java.net.*;
import java.io.*;

class chatclient{
	public static void main(String args[]) throws IOException{
		Socket s=new Socket("localhost",8008);
		BufferedReader br=new BufferedReader(new InputStreamReader(s.getInputStream()));
		PrintWriter w=new PrintWriter(s.getOutputStream(),true);
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		String m;
		while(true){
		m=in.readLine();
		w.println(m);
		String b=br.readLine();
		System.out.println("server: "+b);}
}
}

