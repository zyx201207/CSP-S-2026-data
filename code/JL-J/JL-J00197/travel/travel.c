#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n1,n2;
    string x1,x2;
    bool a,b,c,d;
    cin>>n1>>x1>>n2>>x2;
    a=d=1;
    b=c=0;
    if(n1!=n2){
        a=b=c=d=0;
        cout<<a<<b<<c<<d;
    }
    if(x1[0]==x2[0] && x1[1]==x2[1]) b=1;
    else{
        c=d=0;
        cout<<a<<b<<c<<d;
    }
    if(c==0) d=0;
    if(x1[2]=='A') if(x2[2]!='B') d=0;
    if(x1[2]=='B') if(x2[2]!='A'||x2[2]!='C') d=0;
    if(x1[2]=='C') if(x2[2]!='B') d=0;
    if(x1[2]=='D') if(x2[2]!='F') d=0;
    if(x1[2]=='F') if(x2[2]!='D') d=0;
    cout<<a<<b<<c<<d;
    return 0;
}






