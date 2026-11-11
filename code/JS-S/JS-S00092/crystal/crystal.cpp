#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5e5+10;
ll n,m,ans=-1,a[M],d[M],sum[M],sum2[M];
bool check(ll x,ll id)
{
    ll cost=0;
    cost=(id-x)*sum[id-1];
    cost=cost-(sum2[max(id-2,0ll)]-sum2[max(x-2,0ll)]);
    //cout<<"x is "<<x<<" id is "<<id<<" cost is "<<cost<<";check= "<<(cost<=m)<<endl;
    if(cost<=m) return 1;
    return 0;
}
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
    for(int i=1;i<n;i++)
    {
        d[i]=a[i+1]-a[i];
    }
    //bool task1=1;
    for(int i=1;i<n;i++)
    {
        //if(d[i]!=d[i-1]&&i!=1) task1=0;
        sum[i]=sum[i-1]+d[i];
    }
    for(int i=1;i<=n;i++)
    {
        sum2[i]=sum2[i-1]+sum[i];
    }
    //if(task1==1)
    //{
    //    for(int i=1;i<=n;i++)
    //   {
    //      ll t=(i-1)*i/2*d[1];
    //        if(t>m)
    //        {
    //            ans=i-1;
    //            break;
    //        }
    //    }
        //cout<<ans;
    //    return 0;
    //}
    for(ll i=1;i<=n;i++)
    {
        ll l=1,r=i,mid,pos=1;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(check(mid,i)==1)
            {
                r=mid-1;
                pos=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        //cout<<"mid is "<<mid<<",i is "<<i<<",pos is "<<pos<<endl;
        ans=max(ans,i-pos+1);
    }
    cout<<ans;
    return 0;
}
