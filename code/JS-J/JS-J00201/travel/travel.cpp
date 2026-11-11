#include<bits/stdc++.h>
using namespace std;
#define ll long long

signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c) cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    if(b[0]==d[0]&&b[1]==d[1]) cout<<"1";
    else{
        cout<<"000";
        return 0;
    }
    char x=b[2],y=d[2];
    if(x>y) swap(x,y);
    if(x=='A'&&y=='B'||x=='A'&&y=='C'||x=='B'&&y=='C'||x=='D'&&y=='F') cout<<"1";
    else{
        cout<<"00";
        return 0;
    }
    if(x=='A'&&y=='B'||x=='B'&&y=='C'||x=='D'&&y=='F') cout<<"1";
    else cout<<"0";
    return 0;
}
