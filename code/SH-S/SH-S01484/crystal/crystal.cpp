#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=5e5+10;
long long a[maxn],d[maxn];
long long m;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=n-1;i>=1;i--) d[i]=a[i+1]-a[i];
    int ans;
    if(n<=5000)
    {
        ans=0;
        for(int i=n;i>=1;i--)
        {
            long long mm=m;
            int p=i-1;
            while(mm-d[p]>=0 && p)
            {
                mm-=1ll*d[p]*p;
                p--;
            }
            ans=max(ans,i-p);
        }
    }
    else
    {
        int l=1,r=n;
        while(l<r)
        {
            int i=(l+r)/2;
            long long s=a[i]*(i-1)-(a[i-1]+a[1])*(i-1)/2;
            if(s<=m)
            {
                l=i+1;ans=i;
            }
            else r=i;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
