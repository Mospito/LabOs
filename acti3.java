import java.util.Random; //_____________________________________
 import java.io.*; //_____________________________________
 /*__________________________________________*/

public class acti3 {
public static void main(String[] args) {
int num = 0;

/*______________________________________________________*/


if(args.length < 1) {
System.out.println("\n This program requires an integer argument.");
System.exit(1);
}
 /*_______________________________________*/


try {
num = Integer.parseInt(args[0]);
}
catch (NumberFormatException nfe) {
System.out.println("The first argument must be an integer.");
System.exit(1);
}
System.out.println("\n You enter " + num);
 /*___________________________________________*/

Random randomGenerator = new Random();
int randomInt = randomGenerator.nextInt(100);
 /*___________________________________________*/


if(num < randomInt) {
System.out.println("You lost!");
System.out.println("Number of Random = " + randomInt); /*Check Random*/ 
}
else if(num > randomInt) {
System.out.println("You won! ");
System.out.println("Number of Random = " + randomInt); /*Check Random*/ 
}
else {
System.out.println("Wow! We should go out coz we think alike.");
}
}
}