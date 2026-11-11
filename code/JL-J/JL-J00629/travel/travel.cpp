#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n1,n2;
    string m1,m2;
    bool a,b,c,d;
    cin>>n1>>m1>>n2>>m2;
    a=d=1;
    b=c=0;
    if(n1!=n2){
        a=b=c=d=0;
        cout<<a<<b<<c<<d;
        return 0;
    }
    if(m1[0]==m2[0]&&m1[1]==m2[1]) b=1;
    else{
        c=d=0;
        cout<<a<<b<<c<<d;
        return 0;
    }
    if(m1[2]=='A'&&m2[2]=='B'||m1[2]=='A'&&m2[2]=='C'||m1[2]=='B'&&m2[2]=='A'||m1[2]=='B'&&m2[2]=='C'||m1[2]=='C'&&m2[2]=='A'||m1[2]=='C'&&m2[2]=='B'||m1[2]=='D'&&m2[2]=='F'||m1[2]=='F'&&m2[2]=='E') c=1;
    if(c==0) d=0;
    if(m1[2]=='A') if(m2[2]!='B') d=0;
    if(m1[2]=='B') if(m2[2]!='A'&&m2[3]!='C') d=0;
    if(m1[2]=='C') if(m2[2]!='B') d=0;
    if(m1[2]=='D') if(m2[2]!='F') d=0;
    if(m1[2]=='F') if(m2[2]!='D') d=0;
    cout<<a<<b<<c<<d;
return 0;
}
