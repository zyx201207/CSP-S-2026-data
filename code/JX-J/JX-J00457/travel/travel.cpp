#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int ans=1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a!=c) ans=0;
    cout<<ans;
    if(!(ans&&b[0]==d[0]&&b[1]==d[1])) ans=0;
    cout<<ans;
    if(ans){
        if(b[2]<='C'&&d[2]<='C');
        else if(b[2]>'C'&&d[2]>'C');
        else ans=0;
    }
    cout<<ans;
    if(ans){
        if((b[2]+1)==d[2]||(d[2]+1)==b[2]||b[2]>'C'&&d[2]>'C');
        else ans=0;
    }
    cout<<ans;
}
