#include<bits/stdc++.h>
using namespace std;
#define int long long 

inline int read(){
    int f=0,num=0,c=cin.rdbuf()->sbumpc();
    while(!isdigit(c)){
        if(c=='-')f=1;
        c=cin.rdbuf()->sbumpc();
    }
    while(isdigit(c)){
        num=(num<<1)+(num<<3)+(c^48);
        c=cin.rdbuf()->sbumpc();
    }
    return f?-num:num;
}


signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int o1=1,o2=1,o3=1,o4=1;
    if(a==c){
        o1=1;
    }
    else{
        o1=0;
    }
    if(b.substr(0,2)==d.substr(0,2)){
        o2=1;
    }
    else{
        o2=0;
    }
    o2&=o1;
    int u=b.back(),v=d.back();
    if((u<='C'&&v<='C')||(u>'C'&&v>'C')){
        o3=1;
    }
    else{
        o3=0;
    }
    o3&=o2;
    if(u>v)swap(u,v);
    if((u=='A'&&v=='B')||(u=='B'&&v=='C')||(u=='D'&&v=='F')){
        o4=1;
    }
    else{
        o4=0;
    }
    o4&=o3;
    cout<<o1<<o2<<o3<<o4;
    return 0;
}