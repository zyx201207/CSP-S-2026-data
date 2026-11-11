#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;

int n,m;
int a[N];
int tot,ans;

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int l=1,r=1;r<=n;r++)
    {
        if(r!=1)
            tot+=(r-l)*(a[r]-a[r-1]);
        while(tot>m)
            tot-=a[r]-a[l],l++;
        // cout<<l<<' '<<r<<'\n';
        ans=max(ans,r-l+1);
    }
    cout<<ans<<'\n';

    return 0;
}