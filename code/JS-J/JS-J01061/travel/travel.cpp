#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2,ans;
bool sc,sp,ss,near;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1){
        sc=true;
    }
    int a,b;
    a=(a2[0]-'0')*10+a2[1]-'0';
    b=(b2[0]-'0')*10+b2[1]-'0';
    if(sc&&a==b){
        sp=true;
    }
    int c=0;
    if(a2[2]<b2[2]){
        c=b2[2]-a2[2];
    }else{
        c=a2[2]-b2[2];
    }
    int aw,bw;
    if(a2[2]>'C') aw=1;
    else aw=-1;
    if(b2[2]>'C') bw=1;
    else bw=-1;
    if(sc&&sp&&aw==bw) ss=true;
    if(sc&&sp&&ss&&c<=1) near=true;
    if(sc) ans+='1';
    else ans+='0';
    if(sp) ans+='1';
    else ans+='0';
    if(ss) ans+='1';
    else ans+='0';
    if(near) ans+='1';
    else ans+='0';
    cout<<ans;
    return 0;
}
