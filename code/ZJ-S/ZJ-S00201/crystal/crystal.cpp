#include <bits/stdc++.h>
using namespace std;
#define int long long

constexpr int maxn=5e5+10;

int a[maxn];
int n,m;

inline void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=2;i<=n;++i)
    {
        int cnt=0;
        int sum=0;
        for(int j=i;j;--j)
        {
            if(sum<=m)
            {
                sum+=(a[i]-a[j]);
                ++cnt;
            }
            else break;
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<'\n';
}

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
