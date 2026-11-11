#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long sum[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    //cout<<67676767;
    long long m;
    cin>>n>>m;
    //<<67<<n<<m<<"\n";
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    int maxn=0;
    for(int i=2;i<=n;i++)
    {
        int l=1;
        int r=i-1;
        int res=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if((a[i]*1ll*(i-mid+1)-(sum[i]-sum[mid-1]))<=m)
            {
                r=mid-1;
                res=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        maxn=max(maxn,i-res+1);
    }
    cout<<maxn<<"\n";
    return 0;
}
