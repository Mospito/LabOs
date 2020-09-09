import java.io.*;

import javax.sound.midi.Sequence;


//Class Run Thread
class RunRun implements Runnable
{ 
    private int tmp;
    private int[] sum;
    private String[] ch;
    //Get Data
    public  int SeeInt()
    {
        return this.tmp;
    }

    //Set Data
    public void setInt(int x)
    {
        this.tmp = x;
    }
    public RunRun (int s)
    {
        this.tmp = s;
         
    }
    //Method Sequence
    public void Sequence()
    {
            int[] num;
            num = new int[this.tmp]; //Defind Arr
            num[0] = 1;
            num[1] = 1;
            num[2] = 2;
            num[3] = 2;

            this.sum = new int[this.tmp];
            this.sum [0] = 1;
            this.sum [1] = 1;
            this.sum [2] = 2;
            this.sum [3] = 2;
            //6135512026
            for(int i=4; i<this.tmp; i++)
            {

               if(i > 3)
               {
                    if( i % 3 == 0)    //if n is a multiple of 3
                    {
                        num[i] = num[i-1];
                        
                    }
                    else //otherwise
                    {
                        num[i] = num[i-2]+num[i-2]-1;
                        
                    }
                    this.sum[i] = num[i];//Set Value of Sum[i]  = num[i]
               }
               
                 
              //6135512026
              
            }
            
            
    }
    //Run Thread
    public void run() 
    { 
        this.Sequence();//Call Method Sequence
          try
          { 
            
            // Displaying the thread that is running 
            System.out.println ("Thread ID: " + 
                                Thread.currentThread().getId() + 
                                " is running" +"___"+"Ans. ----> "+ java.util.Arrays.toString(this.sum) );  //To String
                                
  
         } 
        //6135512026
        catch (Exception e) 
        { 
            // Throwing an exception 
            System.out.println ("Exception is caught Err Naja EiEi"); 
        } 
    }
    
} 

//Main Class
public class S6135512026h5 {
    public static void main(String[] args) 
    {   //6135512026
        int n = 3; // Number of threads  = 3 Because My number 026  and 6 is event ,So n = 3
        int number = Integer.parseInt(args[0]);  //String to Integer
        for (int i=0; i<n; i++) 
        { 
            Thread t = new Thread(new RunRun(number));   //Create Thread and Send Integer 
            t.start();  //Run Thread
        } 
    } 

}

  
