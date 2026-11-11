#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    bool a,b,c,d;
    a=b=c=d=1;
    if(c1==c2){
        a=1;
    }else{
        a=0;
        b=c=d=0;
    }
    char x,y;
    string m,n;
    m="";n="";
    for(int i=0;i<3;i++){
        x=s1[i];y=s2[i];
        if(i<2){
            m=m+x;
            n=n+y;
        }
    }
    if(b&&m==n){
        b=1;
    }else{
        b=c=d=0;
    }
    if(c&&((x>='A'&&x<='C')&&(y>='A'&&y<='C')||(x=='F'&&y=='D')||(y=='F'&&x=='D'))){
        c=1;
    }else{
        c=d=0;
    }
    if(a&&b&&c&&(x-y==1||y-x==1)){
        d=1;
    }else{
        d=0;
    }
    cout<<a<<b<<c<<d;
    return 0;
}
