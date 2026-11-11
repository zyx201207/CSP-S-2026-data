#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
bool CK(int F)
{
    int L=1,R=F;
    //cout<<F<<endl;
    long long sum=0;
    for(int i=1;i<=F;i++)
    {
        sum+=a[F]-a[i];
    }
    for(int i=F;i<=n;i++)
    {
        //cout<<sum<<" ";
        if(sum<=m)
        {
            return 1;
        }
        if(i<n)
        {
            sum+=1ll*F*(a[i+1]-a[i]);
            sum-=(a[i+1]-a[i-F+1]);
        }
    }
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
    int l=1,r=n,mid;
    while(l<=r)
    {
        //cout<<l<<" "<<r<<endl;
        mid=(l+r)/2;
        if(CK(mid))
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<r;
}
