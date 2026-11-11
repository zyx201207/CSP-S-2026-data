#include <bits/stdc++.h>
using namespace std;
const int N=2e3+10;
typedef long long LL;
LL n,m;
LL a[N];
LL dp[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    LL maxn=0;
    for(int i=1;i<=n;i++)cin>>a[i],maxn=max(maxn,a[i]);
    //sort(a+1,a+n+1);
    memset(dp,-0x3f,sizeof(dp));
    if(m==1)
    {
        cout<<maxn<<'\n';
        return 0;
    }
    else if(m==n)
    {
        LL ans=a[1];
        for(int i=2;i<=n;i++)ans=ans&a[i];
        cout<<ans<<'\n';
        return 0;
    }
    else if(m==2)
    {
        LL ans=0;
        for(int i=1;i<=n-1;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans<<'\n';
        return 0;
    }
    else cout<<0<<endl;
    return 0;
}
