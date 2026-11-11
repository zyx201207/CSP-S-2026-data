#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else cout<<0;
    if(s1.substr(0,2)==s2.substr(0,2)&&c1==c2) cout<<1;
    else cout<<0;
    if(s1.substr(0,2)==s2.substr(0,2)&&
    c1==c2&&
    ((s1.back()<='C'&&s2.back()<='C')
    ||(s1.back()>='D'&&s2.back()>='D')
    )) cout<<1;
    else cout<<0;
    if(s1.substr(0,2)==s2.substr(0,2)
    &&c1==c2
    &&((s1.back()<='C'&&s2.back()<='C')
    ||(s1.back()>='D'&&s2.back()>='D'))
    &&abs(s1.back()-s2.back())==1) cout<<1;
    else cout<<0;
}