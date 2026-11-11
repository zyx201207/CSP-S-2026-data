#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>c>>b>>d;
    if(a==b)cout<<1;
    else{
        for(int i=0;i<4;i++)cout<<0;
        return 0;
    }
    if(b[0]==d[0] && b[1]==d[1])cout<<1;
    else {
        for(int i=0;i<3;i++)cout<<0;
        return 0;
    }
    if((b[2]<='C' && d[2]<='C') || (b[2]>='D' && d[2]>='D')){
        cout<<1;
        if(b[2]>='D' && d[2]>='D')cout<<1;
        else if(b[2]=='B' || d[2]=='B')cout<<1;
        else cout<<0;
    }
    else cout<<0,cout<<0;
    return 0;
}
