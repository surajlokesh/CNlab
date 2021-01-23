#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

int gcd(int a, int b) {
   int t;
   while(1) {
      t= a%b;
      if(t==0)
      return b;
      a = b;
      b = t;
   }
}
double RSA ( double val, int mode) {
   double p = 13;
   double q = 11;
   double n=p*q;
   double track;
   double phi= (p-1)*(q-1);
   
   double e=7;
   
   while(e<phi) {
      track = gcd(e,phi);
      if(track==1)
        break;
      else
        e++;
   }
   
   double d1=1/e;
   double d=fmod(d1,phi);
   double c = pow(val,e); 
   double m = pow(c,d);
   c=fmod(c,n);
   m=fmod(m,n);
   if (mode == 1){
       return c;
   }
   else{
       return m;
   }
}

int main(){
    string msg,encr,dcr;
    int opt;
    do{
        cout << "1.Encrypt\n2.Decrypt\n3.Exit\nEnter Choice: ";
        cin >> opt;
        getchar();
        if(opt==1){
            cout << "Enter the message:";
            getline(cin,msg);
            encr=dcr=msg;
            for(int i=0;i<encr.length();i++){
                encr[i]=char(RSA(double(encr[i]),1));
            }
            cout << encr << endl;
        }
        else if(opt==2){
            for(int i=0;i<dcr.length();i++){
                dcr[i]=char(RSA(double(dcr[i]),0)+1);
            }
            cout << dcr <<endl;
        }        
        else{
            exit(0);
        }
    }while(true);    
    return 0;
}