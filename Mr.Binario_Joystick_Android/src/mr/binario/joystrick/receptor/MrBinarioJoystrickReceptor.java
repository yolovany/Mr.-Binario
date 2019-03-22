/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mr.binario.joystrick.receptor;

import java.io.IOException;

/**
 *
 * @author Jovany
 */
public class MrBinarioJoystrickReceptor {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        ThreadServidor threadServidor = new ThreadServidor();
        threadServidor.start();
    }
    
}
