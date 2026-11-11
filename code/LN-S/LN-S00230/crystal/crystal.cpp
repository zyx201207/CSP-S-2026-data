#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010],presum[500010];
bool check(int mid)
{
    for(int l=1;l+mid-1<=n;l++)
    {
        int r=l+mid-1;
        if(m>=a[r]*mid-(presum[r]-presum[l-1]))return true;
    }
    return false;
}
inline void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)presum[i]=presum[i-1]+a[i];
    //er fen len
    int l=1,r=n,mid;
    int ans=1;
    while(l<=r)
    {
        mid=l+r>>1;
        if(check(mid))
        {
            l=mid+1;
            ans=mid;
        }
        else r=mid-1;
    }
    cout<<ans<<'\n';
    return ;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--)solve();
    return 0;
}
