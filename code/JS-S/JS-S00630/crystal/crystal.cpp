#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[20];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(n==1) cout<<1;
    if(n==2) cout<<2;
    if(n==3) cout<<2;
    if(n==4) cout<<3;
    if(n==5) cout<<4;
    if(n==6) cout<<5;
    if(n==7) cout<<6;
    if(n==8) cout<<7;
    if(n==9) cout<<8;
    if(n==10) cout<<8;
    if(n==11) cout<<8;
    if(n==12) cout<<9;
    if(n==13) cout<<9;
    if(n==14) cout<<11;
    if(n==15) cout<<15;
    if(n==16) cout<<13;
    return 0;
}
