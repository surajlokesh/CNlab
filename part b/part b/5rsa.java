import java.util.*;
import java.io.*;
import java.math.BigInteger; 
class rsa
{   
    public static void main(String []args)
    {
        Scanner s=new Scanner(System.in);
        System.out.println("Enter the Message value(M)");
        int m=s.nextInt();    
        System.out.println("Enter the public key value(e)");
        int e=s.nextInt();
        System.out.println("Enter the values :(p) and (q)");
        int p=s.nextInt();
        int q=s.nextInt();
        int t=(p-1)*(q-1);
        int n=p*q;
        System.out.println(n);
        int d=0;
        for(int i=1;i<t;i++)
        {
            int pp=(e*i)-1;
            if(pp%t==0)
            {   
                d=i;
                break;
            }
        }
        BigInteger m1=new BigInteger(String.valueOf(m));
        BigInteger e1=new BigInteger(String.valueOf(e));
        BigInteger n1=new BigInteger(String.valueOf(n));
        BigInteger d1=new BigInteger(String.valueOf(d));
        BigInteger c=m1.modPow(e1,n1);   
        System.out.println("Encrypted message for message "+m+" is "+c);
        BigInteger mm=c.modPow(d1,n1);
        System.out.println("Decrypted message for cipher "+c+" is "+mm);
        if(m1.equals(mm))
           System.out.println("Decryption succesfull");
    }
}
    
     
