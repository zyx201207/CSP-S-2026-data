#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
int n,m;
int a[N];
int det[N];//the det between the a[i] and a[i+1]
int sum[N];//the sum that from 1 to i cost
int ans=0;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=(int)1e12;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n-1;i++)
    {
        det[i]=a[i+1]-a[i];
    }

    sum[1]=0;
    for(int i=2;i<=n;i++)
    {
        sum[i]=sum[i-1]+det[i-1]*(i-1);
    }

    for(int i=1;i<=n;i++)
    {
        int r=n,cost=0;
        for(int r=n;r>=i;r--)
        {
            cost=sum[r]-(sum[i]+(a[r]-a[i])*(i-1));
            if(m>=cost)
            {
                ans=max(ans,r-i+1);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
