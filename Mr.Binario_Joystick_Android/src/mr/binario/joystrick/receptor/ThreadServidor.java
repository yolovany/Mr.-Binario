package mr.binario.joystrick.receptor;


import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Jovany
 */
public class ThreadServidor extends Thread{

final int PUERTO=12345;

ServerSocket sc;

Socket so;

//SERVIDOR

    @Override
    public void run() {
            BufferedReader entrada;
                try
            {
                sc = new ServerSocket(PUERTO );/* crea socket servidor que escuchara en puerto 5000*/
                //so=new Socket();
                System.out.println("Esperando una conexión:");
                so=sc.accept();
                //Inicia el socket, ahora esta esperando una conexión por parte del cliente
                
                
                if(so.isConnected())
                {
                    System.out.println("Conexión establecida");
                    
                    while(true){
                        entrada = new BufferedReader(new InputStreamReader(so.getInputStream()));
                        System.out.println(entrada.readLine());
                    }
                }
                else
                    System.out.println("Ningún dispositivo conectado.");
                
            }catch(Exception e ) {
                System.out.println("Error: "+e.getMessage());
            }
    }        
}
