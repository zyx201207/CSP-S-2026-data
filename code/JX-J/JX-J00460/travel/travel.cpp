#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int a=0,b=0,c=0,d=0;
bool check(char x,char y){
    if(x>='A'&&x<='C'&&y>='A'&&y<='C'){
        //cout<<1<<endl;
        return true;
    }
    else if((x=='D'||x=='F')&&(y=='D'||y=='F')){
        //cout<<2<<endl;
        return true;
    }
    //cout<<3<<endl;
    return false;
}
int main(){
    freopen("travel4.in","r",stdin);
    freopen("travel4.out","w",stdout);
    cin>>s1>>s2>>c1>>c2;
    if(s1==c1)a=1;
    if(a==1&&s2[0]==c2[0]&&s2[1]==c2[1])b=1;
    if(b==1&&check(s2[2],c2[2])==1)c=1;
    //cout<<s2[2]<<" "<<c2[2]<<" "<<check(s2[2],c2[2])<<" "<<c<<endl;
    if(c==1&&(abs(s2[2]-c2[2])==1||(c==1&&s2[2]=='D'||s2[2]=='F')))d=1;
    cout<<a<<b<<c<<d;
    return 0;
}
