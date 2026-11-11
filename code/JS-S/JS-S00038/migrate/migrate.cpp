#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6+5;
int n,d,x[maxn];
void solve1112()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>x[i];
    int m=x[2]-x[1];
    for(int i=2;i<=n;i++)
    {
        if(i*m<=d&&(i+1)*m>d)
        {
            if(i+i-1<=n)
            {
                cout<<n-(i+i-1)<<'\n';
                return;
            }
            break;
        }
    }
    cout<<"0\n";
    return;
}
void solve1314()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>x[i];
    int r=1,ans=0;
    for(int l=1;l<=n;l++)
    {
        while(r<=n&&x[r+1]-x[l]<=d) r++;
        ans+=(n-r);
    }
    cout<<ans<<'\n';
    return;
}
void solve()
{
    cout<<"0\n";
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int c,t; cin>>c>>t;
    if(c==11||c==12) while(t--) solve1112();
    else if(c==13||c==14) while(t--) solve1314();
    else while(t--) solve();
    return 0;
}
