#include <bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long a[N],n,m,sum[N],ans;
bool check(long long x)
{
//    cout<<x<<":"<<endl;
    for(long long i=1;i+x-1<=n;i++)
    {
        long long j=i+x-1;
        long long k=x*a[j]-sum[j]+sum[i-1];
//        cout<<i<<" "<<j<<":"<<k<<" "<<m<<endl;
        if(k<=m)
            return true;
    }
    return false;
}
void ef()
{
    long long l=1,r=n;
    while(l<=r)
    {
        long long mid=(l+r)>>1;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    ef();
    cout<<ans;
    return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
