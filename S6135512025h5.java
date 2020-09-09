import java.io.*;

//Class Thread Working
class ThreadDemo implements Runnable {
    Thread t,t2;
    private int tmp;
    public ThreadDemo(int x) {
       this.tmp = x;

    }

    
    public void run() {
      System.out.print("Thread  "+Thread.currentThread().getId()+":  "); //Show CurrentThread ID
      //Sequence
       int[] s = new int[this.tmp];
       s[0] = 1;
       s[1] = 1;
       s[2] = 2;
       s[3] = 2;
      
      
       for(int i=4; i<this.tmp; i++)
       {
             if(i%3 == 0)
             {
                s[i] = s[i-1]; //if n is a multiple of 3
             }
             else //otherwise
             {
                s[i] = s[i-2] + s[i-2] -1;
             }
          
       }
       //Show Output 
       for(int j=0; j<this.tmp; j++)
       {
          System.out.print(s[j]+" ");
       }
       System.out.println("");
       System.out.println("Finish Sequence Form Thread ID:"+Thread.currentThread().getId());   //Show CurrentThread ID
       System.out.println("Exiting the  thread"+"  Thread ID is : "+Thread.currentThread().getId()); //Show CurrentThread ID
   
      
    }
 }

//Class main
 public class S6135512025h5 {
    public static void main(String args[]) {

      int num = Integer.parseInt(args[0]); //Parse String to Integer 
      //6135512025  025 = Odd ,So My M is 2 
      Thread t,t2;   // 2 Threads

      //Create Thread 1
      t = new Thread(new ThreadDemo(num));
      t.start();

      String ID = Thread.currentThread().getName(); 
      if(ID == t.currentThread().getName())   //Condition for sleep
      {
         try
         {
            Thread.sleep(500); //Sleep 0.5 millis
         }
         catch(InterruptedException e)
         {
            System.out.println(e);
         }  
      }
     //Create Thread 2
      t2 = new Thread(new ThreadDemo(num));
      t2.start();
     

       
    }
 }