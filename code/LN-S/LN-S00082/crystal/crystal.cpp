#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long n,m,a[maxn],c[maxn];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        c[i]=a[i]+c[i-1];
    }
    long long maxx=0;
    for(int i=1;i<=n;i++)
    {
        long long l=1,ans=-1,r=i;
        while(l<=r)
        {
            long long mid=(l+r)>>1;
            if(a[i]*(i-mid)-(c[i-1]-c[mid-1])<=m)
            {
                r=mid-1;
                ans=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        maxx=max(maxx,i-ans+1);
    }
    cout<<maxx;
    return 0;
}
