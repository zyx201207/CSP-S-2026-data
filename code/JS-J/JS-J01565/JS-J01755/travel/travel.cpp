#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c1,s1,c2,s2;
    char r1,r2;
    cin>>c1>>s1>>r1>>c2>>s2>>r2;
    if(c1==c2)cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(s1==s2)cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if(r1<='C'&&r2<='C')cout<<1;
    else if(r1>='D'&&r2>='D')cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if(r1=='D'&&r2=='F')cout<<1;
    else if(abs(r1-r2)==1)cout<<1;
    else cout<<0;
    return 0;
}
