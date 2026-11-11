#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long m,n,a[N],ans=1,maxn=0,cnt=0;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }

    sort(a,a+n);

    for(long long l=0,r=1;l<n,r<n;r++)
    {
        long long z=a[r]-a[r-1];
        if(z+cnt>m)
        {
            long long t=a[l+1]-a[l];
            cnt-=t;
            l++;
            ans--;
            r--;
        }
        if(z+cnt<=m)
        {
            cnt+=z;
            ans++;
        }
        maxn=max(maxn,ans);
    }

    cout<<maxn;

    return 0;
}
