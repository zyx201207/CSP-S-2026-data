#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,cnt,k;
int a[500010];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        cnt=0;
        k=0;
        for(int j=i;j>=1;j--)
        {
            if(k+a[i]-a[j]<=m)
            {
                k+=a[i]-a[j];
                cnt++;
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
