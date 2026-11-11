#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005];
long long m,s[500005];
bool check(int k)
{
    for(int i=k;i<=n;i++)
    {
        long long sum=s[i]-s[i-k+1]-(i-k)*(a[i]-a[i-k+1]);
//        cout<<sum<<" ";
        if(sum<=m) return true;
    }
//    cout<<"\n";
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+1ll*(i-1)*(a[i]-a[i-1]);
//        cout<<s[i]<<" ";
    }
//    cout<<"\n";
    int l=1,r=n;
    int mid=(l+r)/2;
    while(l<=r)
    {
//        cout<<mid<<"\n";
        if(check(mid))
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
        mid=(l+r)/2;
    }
    cout<<mid;
    return 0;
}
