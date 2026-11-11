#include<bits/stdc++.h>
using namespace std;
int a,b,x,y;
char c,aa,bb;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>c;
    x=c-'0';
    cin>>c;
    x*=10;
    x+=c-'0';
    cin>>aa>>b>>c;
    y=c-'0';
    cin>>c;
    y*=10;
    y+=c-'0';
    cin>>bb;
    cout<<(a==b)<<(a==b&&x==y)<<(a==b&&x==y&&!(aa<'D'^bb<'D'))<<(a==b&&x==y&&!(aa<'D'^bb<'D')&&abs(aa-bb)==1);
    return 0;
}
