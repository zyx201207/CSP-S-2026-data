#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c,d;
char ca,cb;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b>>ca>>c>>d>>cb;
    if(ca=='F') ca--;
    if(cb=='F') cb--;
    cout<<(a==c)<<(a==c&&b==d)<<(a==c&&b==d&&(ca<='C')==(cb<='C'))<<(a==c&&b==d&&(ca<='C')==(cb<='C')&&abs(ca-cb)==1);
    return 0;
}
