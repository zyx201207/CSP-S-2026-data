#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005],cha[500005];
int n;
long long m;
bool check(int x)
{
    for(int i=x;i<=n;i++)
    {
        //cout<<"check:"<<cha[i]+sum[i-x]-a[i]*(i-x)<<"\n";
        if(cha[i]+sum[i-x]-a[i]*(i-x)<=m) return true;
        //int cnt=0;
        //for(int j=i-1;j>=i-x+1;j--)
        //{
           // cnt+=a[i]-a[j];
        //}
        //if(cnt<=m)
        //{
        //    return true;
        //}
    }
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
        if(i>=2) cha[i]=(i-1)*a[i]-sum[i-1];
    }
    int l=0,r=n,ans=0;
    while(l<=r)
    {
        int mid=l+((r-l)>>1);
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
