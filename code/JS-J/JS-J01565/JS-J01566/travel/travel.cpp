#include<bits/stdc++.h>
using namespace std;
char y[10],b[10];
int n,m;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>y[1]>>y[2]>>y[3]>>m>>b[1]>>b[2]>>b[3];
    if(y[3]=='D'||y[3]=='F') y[3]+=2;
    if(b[3]=='D'||y[3]=='F') b[3]+=2;
    if(n==m) cout<<1;
    else cout<<0;
    if(n==m&&y[1]==b[1]&&y[2]==b[2]) cout<<1;
    else cout<<0;
    if(n==m&&y[1]==b[1]&&y[2]==b[2]&&abs(y[3]-b[3])<=2) cout<<1;
    else cout<<0;
    if(n==m&&y[1]==b[1]&&y[2]==b[2]&&abs(y[3]-b[3])==1) cout<<1;
    else cout<<0;
    return 0;
}
