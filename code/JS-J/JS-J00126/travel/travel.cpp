#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int work1(){
    if(s1==s3){
        return 1;
    }else{
        return 0;
    }
}
void work2(){
    int num1=0;
    char ch1;
    for(int i=0;i<s2.size();i++){
        if(s2[i]>='0'&&s2[i]<='9'){
            num1=num1*10+(int)(s2[i]-48);
        }else{
            ch1=s2[i];
        }
    }
    int num2=0;
    char ch2;
    for(int i=0;i<s4.size();i++){
        if(s4[i]>='0'&&s4[i]<='9'){
            num2=num2*10+(int)(s4[i]-48);
        }else{
            ch2=s4[i];
        }
    }
    if(ch1=='F'){
        ch1='E';
    }
    if(ch2=='F'){
        ch2='E';
    }
    int f=0;
    if(work1()&&num1==num2){
        cout<<1;
        f=1;
    }else{
        cout<<0;
    }
    if(f&&(ch1<='C'&&ch2<='C')||(ch1>='D'&&ch2>='D')){
        cout<<1;
        f=1;
    }else{
        cout<<0;
        f=0;
    }
    if(f&&((char)(ch1+1)==ch2||(char)(ch1-1)==ch2)){
        cout<<1;
    }else{
        cout<<0;
    }
    cout<<"\n";
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    cout<<work1();
    work2();
    return 0;
}