#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],maxn=0;
int sum[500005];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int cnt=0,id=0;
    a[n+1]=1e18;
    for(int i=1;i<=n+1;i++)
    {
        if(a[i]!=a[i-1]&&i>1)
        {
            int l=0,r=id;
            while(l+1<r)
            {
                int mid=(l+r)/2;
                int cct=id-mid;
                if(cct*a[id]-(sum[id-1]-sum[mid-1])<=m) r=mid;
                else l=mid;
            }
            maxn=max(maxn,id-r+cnt);
            cnt=1;
        }
        else cnt++;
        if(a[i]!=a[i-1]) id=i;
    }
    cout<<maxn;
    return 0;
}