#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;char x,y;
    cin>>a>>b>>x>>c>>d>>y;
    if(a!=c)cout<<"0000";
    else{
        if(b!=d)cout<<"1000";
        else{
            if(!(x<='C'&&y<='C'||x>='D'&&y>='D'))cout<<"1100";
            else{
                if(x>y)swap(x,y);
                if(x=='A'&&y=='B'||x=='B'&&y=='C'||x=='D'&&y=='F')cout<<"1111";
                else cout<<"1110";
            }
        }
    }
    return 0;
}
