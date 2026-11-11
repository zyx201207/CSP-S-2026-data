#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2,temp;

int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);


    cin>>c1>>s1>>c2>>s2;

    if(c1!=c2){
        cout<<"0000"<<"\n";
        return 0;
    }

    else{
        temp+='1';
        string num1="",num2="";
        for(int i=0;i<2;i++){
            num1+=s1[i];
            num2+=s2[i];
        }

        int ch1=s1[2]-'A',ch2=s2[2]-'A';

        if(num1!=num2){
            cout<<"1000"<<"\n";
            return 0;
        }
        temp+='1';

        if((ch1>=0&&ch1<=2)&&(ch2>=0&&ch2<=2)||(ch1==3&&ch2==5)||(ch1==5&&ch2==3)) temp+='1';
        else {
            cout<<"1100"<<"\n";
            return 0;
        }

        if(abs(ch1-ch2)==1||(ch1==3&&ch2==5)||(ch1==5&&ch2==3)) temp+='1';
        else {
            cout<<"1110"<<"\n";
            return 0;
        }

        cout<<temp<<"\n";

    }


    return 0;
}
