#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    int num1=0,num2=0;
    for(int i=0;i<a1.size();i++){
        if(i==0&&a1[i]=='0') continue;
        num1=num1*10+a1[i]-'0';
    }
    for(int i=0;i<b1.size();i++){
        if(i==0&&b1[i]=='0') continue;
        num2=num2*10+b1[i]-'0';
    }
    if(num1!=num2){
        cout<<"0000"<<endl;
        return 0;
    }
    else{
        cout<<1;
    }
    num1=0,num2=0;
    for(int i=0;i<a2.size()-1;i++){
        if(i==0&&a2[i]=='0') continue;
        num1=num1*10+a2[i]-'0';
    }
    for(int i=0;i<b2.size()-1;i++){
        if(i==0&&b2[i]=='0') continue;
        num2=num2*10+b2[i]-'0';
    }
    if(num1!=num2){
        cout<<"000"<<endl;
        return 0;
    }
    else{
        cout<<1;
    }
    char n1=a2[a2.size()-1];
    char n2=b2[b2.size()-1];
    if((n1<='C'&&n2<='C')||(n1>'C'&&n2>'C')) cout<<1;
    else{
        cout<<"00"<<endl;
        return 0;
    }
    if(abs((int)n1-(int)n2)==1) cout<<1<<endl;
    else{
        cout<<0<<endl;
        return 0;
    }
    return 0;
}
