#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long a[maxn];
long long p[maxn];
unsigned long long pre[maxn];
bool cmp1(long long a,long long b)
{
    return a<b;
}
long long maxx(long long a,int b)
{
    if(a<b)
        return b;
    return a;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1,cmp1);
    p[1]=a[1];
    for(int i=2;i<=n;i++)
        p[i]=p[i-1]+a[i];
    pre[1]=0;
    for(int i=2;i<=n;i++)
        pre[i]=(long long)i*a[i]-p[i];
    long long ans=-LLONG_MAX;
    for(int i=1;i<=n;i++)
    {
        unsigned long long k=pre[i]+m;
        if(pre[i-1]+m>pre[n]&&k>pre[n])
            break;
        int r=upper_bound(pre+1,pre+n+1,k)-pre;
        ans=maxx(ans,r-i);
    }
    cout << ans << endl;
    return 0;
}
