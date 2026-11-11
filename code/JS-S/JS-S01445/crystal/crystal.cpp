#include<bits/stdc++.h>
#define ll long long
#define lowbits(x) ((x)&(-(x)))
using namespace std;
long long n,a[500005],pos=1,ans[500005];
unsigned long long m;
unsigned long long cnt;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(long long i=2;i<=n;i++)
    {
        long long k=(a[i]-a[i-1])*(i-pos);
        cnt+=k;
        if(cnt>m)
        {
            while(cnt>m)
            {
                cnt=cnt-(a[i]-a[pos]);
                pos++;
            }
        }
        ans[i]=(i-pos+1);
    }
    long long maxn=1;
    for(int i=1;i<=n;i++)
    {
        maxn=max(maxn,ans[i]);
    }
    cout<<maxn;
    return 0;
}


