#include <bits/stdc++.h>
using namespace std;

const int N=5e5+10;
long long n,m,l,r;
long long a[N];
long long sum[N];

bool pd(long long k)
{
    for(int i=k;i<=n;i++) if(a[i]*(k-1)-(sum[i-1]-sum[i-k])<=m) return 1;
    return 0;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    l=1;
    r=n;
    while(l<=r)
    {
        long long d=(l+r)/2;
        if(pd(d)) l=d+1;
        else r=d-1;
    }
    cout<<r;
    return 0;
}
