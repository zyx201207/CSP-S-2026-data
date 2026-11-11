#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int e,f,g,h,i,j;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b>>c>>d;
    e=(a[0]-'0')*10+(a[1]-'0');
    f=(b[0]-'0')*10+(b[1]-'0');
    if(b[2]=='F')b[2]='E';
    g=b[2]-'A';
    h=(c[0]-'0')*10+(c[1]-'0');
    i=(d[0]-'0')*10+(d[1]-'0');
    if(d[2]=='F')d[2]='E';
    j=d[2]-'A';
    if(e==h)cout<<1;
    else cout<<0;
    if(f==i&&e==h)cout<<1;
    else cout<<0;
    if(e==h&&f==i&&((g<=2&&j<=2)||(g>=3&&j>=3)))cout<<1;
    else cout<<0;
    if(e==h&&f==i&&((g<=2&&j<=2)||(g>=3&&j>=3))&&abs(g-j)==1)cout<<1;
    else cout<<0;
    return 0;
}
