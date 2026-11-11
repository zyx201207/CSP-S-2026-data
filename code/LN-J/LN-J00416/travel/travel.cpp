#include<iostream>
using namespace std;
bool judge(char a,char b){
    if(a>='A'&&a<='C'&&b>='A'&&b<='C'&&a!=b)return true;
    if((a=='D'&&b=='F')||(a=='F'&&b=='D'))return true;
    return false;
}
bool judge2(char a,char b){
    if(a>='A'&&a<='C'&&b>='A'&&b<='C'&&b-a==1)return true;
    if(a=='D'&&b=='F')return true;
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,b1;
    string a2,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1)cout<<1;else cout<<0;
    int a3=(a2[0]-'0')*10+a2[1]-'0';
    int b3=(b2[0]-'0')*10+b2[1]-'0';
    if(a1==b1&&a3==b3)cout<<1;else cout<<0;
    if(a1==b1&&a3==b3&&judge(a2[2],b2[2]))cout<<1;else cout<<0;
    if(a1==b1&&a3==b3&&judge(a2[2],b2[2])&&judge2(min(a2[2],b2[2]),max(a2[2],b2[2])))cout<<1;else cout<<0;
    return 0;
}
