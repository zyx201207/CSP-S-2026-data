#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
int ok1,ok2,ok3;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>a>>b>>c>>d;
    if(a==c)cout<<1,ok1=1;
    else cout<<0;
    if(b[0]==d[0]&&b[1]==d[1]&&ok1)cout<<1,ok2=1;
    else cout<<0;
    if('A'<=b[2]&&b[2]<='C'&&'A'<=d[2]&&d[2]<='C'&&ok2)cout<<1,ok3=1;
    else cout<<0;
    if((b[2]+1==d[2]&&b[2]!='C')||b[2]-1==d[2]&&b[2]!='D'&&ok3)cout<<1;
    else cout<<0;
    return 0;
}
