#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
constexpr int maxn=5e5+10;
constexpr int maxm=3e5+1;
int a[maxn],w1[maxn],w2[maxn];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    int sum=0,r=n,ans=0;
    sort(a+1,a+n+1);
    for(int i=n;i>=1;--i)
    {
        while(r)
        {
            sum+=a[i]-a[r];
            if(sum>m)
            {
                sum-=a[i]-a[r];
                ans=max(r-l,ans);
                break;
            }r--;
        }
        sum-=(a[i]-a[i-1])*(i-r-1);
        ans=max(ans,i-l);
    }
    cout<<ans;
    return 0;
}
