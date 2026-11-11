#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=1,ans=1,cost=0;
    while(r<=n)
    {
        if(cost<=m)
        {
            ans=max(ans,r-l+1);
            if(++r>n)break;
            cost+=(r-l)*(a[r]-a[r-1]);
        }
        else
        {
            cost-=(a[r]-a[l]);
            l++;
        }
    }
    cout<<ans;
    return 0;
}
