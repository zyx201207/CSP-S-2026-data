#include <bits/stdc++.h>
using namespace std;
string x,y,p,q;
bool g=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>x>>y>>p>>q;
    if(x[0]==p[0]&&x[1]==p[1]){
        cout<<1;
        g=1;
    }
    else cout<<0;
    if(g==1&&y[0]==q[0]&&y[1]==q[1]){
        cout<<1;
    }
    else{
        cout<<0;
        g=0;
    }
    if(g==1&&((y[2]>='A'&&y[2]<='C'&&q[2]>='A'&&q[2]<='C')||(y[2]>='D'&&y[2]<='E'&&q[2]>='D'&&q[2]<='E'))){
       cout<<1;
    }
    else{
        cout<<0;
        g=0;
    }
    if(g==1&&((y[2]=='A'&&q[2]=='B')||(y[2]=='B'&&q[2]=='C')||(q[2]=='A'&&y[2]=='B')||(q[2]=='B'&&y[2]=='C')||(y[2]=='D'&&q[2]=='F')||(q[2]=='D'&&y[2]=='F'))){
        cout<<1;
    }
    else cout<<0;
    return 0;
}
