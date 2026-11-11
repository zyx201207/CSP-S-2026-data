#include <bits/stdc++.h>
using namespace std;
#define int long long 
string s,g,j,k;
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s>>g>>j>>k;
    if(s==j)cout<<1;
    else cout<<0;
    if(g[0]==k[0]&&g[1]==k[1]&&s==j)cout<<1;
    else cout<<0;
    if(s==j&&g[0]==k[0]&&g[1]==k[1]&&((g[2]<='C'&&k[2]<='C')||(g[2]>='D'&&k[2]>='D')))cout<<1;
    else cout<<0;
if(s==j&&g[0]==k[0]&&g[1]==k[1]&&((g[2]<='C'&&k[2]<='C')||(g[2]>='D'&&k[2]>='D')))
{
    if(abs(g[2]-k[2])<=1&&g[2]!='D'&&k[2]!='D')cout<<1;
    else cout<<0;
}
else cout<<0;

}
