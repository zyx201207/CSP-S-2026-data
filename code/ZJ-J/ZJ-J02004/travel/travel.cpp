#include<bits/stdc++.h>
using namespace std;
int rx,xx;
string rs,xs;
string ans;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rx>>rs>>xx>>xs;
    if(rx!=xx) ans="0000";
    else if((rs[0]!=xs[0])&&(xs[1]!=rs[1])) ans="1000";
    else if((rs[2]<='C'&&xs[2]>='D')||(xs[2]<='C'&&rs[2]>='D'))ans="1100";
    else if(abs(rs[2]-xs[2])!=1)ans="1110";
    else ans="1111";
    cout<<ans;
    return 0;
}
