#include<bits/stdc++.h>
using namespace std;
int x[1000],y[1000],n[10],m[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string  a,s,c,z,n,m;
    int a1=0,a2=0,a3=1,a4=1;
    cin>>a>>s>>c>>z;
    if(a==c) a1=1;
    for(int i=0;i<s.size()-1;i++){
        x[i]=s[i];
    }
    for(int i=0;i<z.size()-1;i++){
        y[i]=z[i];
        if(x[i]==y[i]) a2=1;
    }
    for(int i=2;i<s.size();i++){
        n[i]=s[i];
    }
    for(int i=2;i<z.size();i++){
        m[i]=z[i];
        if(n[1]<='C' && m[1]<='C'){
            a3=1;
        }
        if(n[1]>='C' && m[1]>='C'){
            a3=1;
        }
    }
    for(int i=2;i<z.size();i++){
        if(n[1]=='A'&&m[1]=='B') a4=1;
        if(n[1]=='B'&&m[1]=='A') a4=1;
        if(n[1]=='B'&&m[1]=='C') a4=1;
        if(n[1]=='C'&&m[1]=='B') a4=1;
        if(n[1]=='D'&&m[1]=='F') a4=1;
        if(n[1]=='F'&&m[1]=='D') a4=1;
        if(n[1]=='C' && m[1]=='D') {
            a4=0;
        }
        else if(n[1]=='D' && m[1]=='C'){
            a4=0;
        }
    }
    cout<<a1<<a2<<a3<<a4;
    return 0;
}

