//rp++
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000005];
void solve()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>x[i];
    if(n<=3){cout<<"0\n";return ;}
    int gc=x[2]-x[1],cs=d/gc;
    if(cs<2){cout<<"0\n";return ;}
    cout<<max(0ll,n-cs*2+1)<<'\n';
    return ;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)solve();
    return 0;
}
// 154099
// tanqian99




//Zui hou yi bo!





// 132599
// 132599
// 132599
// 132599
// 132599
// 132599
// 132599
// 132599
