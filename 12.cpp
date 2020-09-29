/*Define a class named as FRACTION that contains two data members that
represent the numerator and denominator of a fraction. By defining
necessary member functions, write a program to add, subtract and multiply
two fractions. The add accepts the objects using call
by- value technique,
subtract using call-by-reference and multiply using call-by-address
technique.
Sample input/Output
For Fraction-1
Enter the numerator: 3
Enter the denominator: 5
For Fraction-2
Enter the numerator: 4
Enter the denominator: 9
Result of addition = 47/45
Result of subtraction = 7/45
Result of multiplication = 4/15*/
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

class fraction{
    int num;
    int den;
    public:
        fraction(){
            num=0;
            den=0;
        }
        void set(int n,int d){
            num=n;
            den=d;
        }
        void add(fraction f1,fraction f2){
            if(f1.den==f2.den){
                num=f1.num+f2.num;
                den=f1.den;    
            }
            else{
                num=f1.num*f2.den+f2.num*f1.den;
                den=f1.den*f2.den;
            }
            
        }
        void sub(fraction &f1,fraction &f2){
            if(f1.den==f2.den){
                num=f1.num-f2.num;
                abs(num);
                den=f1.den;
            }
            else{
                num=f1.num*f2.den-f2.num*f1.den;
                abs(num);
                den=f1.den*f2.den;
            }
        }
        void mul(fraction *f1,fraction *f2){
            num =(*f1).num * (*f2).num;
            den =(*f1).den * (*f2).den;
            int f=0;
            int max=0;
            if(num>den){
                max=num;
            }
            else{
                max=den;
            }
            for(int i=2;i<max;i++){
                f=0;
                for (int j=2;j<=i;j++){
                    if(i%j==0){
                        f++;
                    }
                }
                if(f==1){
                    while(num%i==0&&den%i==0){
                    num=num/i;
                    den=den/i;
                    }        
                }
            }  
        }
        int get_num(){
            return(num);
        }
        int get_den(){
            return(den);
        }
};

int main(){
    fraction f1,f2,f3,f4,f5;
    int n,d;
    cout<<"For Fraction-1"<<endl;
    cout<<"Enter Numerator for first fraction:";
    cin>>n;
    cout<<"Enter Denominator for first fraction:";
    cin>>d;
    f1.set(n,d);
    cout<<"For Fraction-2"<<endl;
    cout<<"Enter Numerator for Second fraction:";
    cin>>n;
    cout<<"Enter Denominator for Second fraction:";
    cin>>d;
    f2.set(n,d);
    f3.add(f1,f2);
    f4.sub(f1,f2);
    f5.mul(&f1,&f2);
    cout<<"Result of addition = "<<f3.get_num()<<"/"<<f3.get_den()<<endl;
    cout<<"Result of subtraction = "<<f4.get_num()<<"/"<<f4.get_den()<<endl;
    cout<<"Result of multiplication = "<<f5.get_num()<<"/"<<f5.get_den()<<endl;
}