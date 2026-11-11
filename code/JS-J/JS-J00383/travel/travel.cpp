#include<bits/stdc++.h>
using namespace std;
string a,b;
int x[3],y[3];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b;
    x[0]=(a[0]-'0')*10+a[1]-'0';
    x[1]=(b[0]-'0')*10+b[1]-'0';
    if(b[2]=='A')x[2]=0;
    if(b[2]=='B')x[2]=1;
    if(b[2]=='C')x[2]=2;
    if(b[2]=='D')x[2]=3;
    if(b[2]=='F')x[2]=4;
    cin>>a>>b;
    y[0]=(a[0]-'0')*10+a[1]-'0';
    y[1]=(b[0]-'0')*10+b[1]-'0';
    if(b[2]=='A')y[2]=0;
    if(b[2]=='B')y[2]=1;
    if(b[2]=='C')y[2]=2;
    if(b[2]=='D')y[2]=3;
    if(b[2]=='F')y[2]=4;
    if(x[0]==y[0])cout<<1;
    else{cout<<"0000";return 0;}
    if(x[1]==y[1])cout<<1;
    else{cout<<"000";return 0;}
    if((x[2]>=3&&y[2]>=3)||(x[2]<3&&y[2]<3))cout<<1;
    else{cout<<"00";return 0;}
    if(x[2]==y[2]+1||x[2]+1==y[2])cout<<1;
    else cout<<0;
    return 0;
}
