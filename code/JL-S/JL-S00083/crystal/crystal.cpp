#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],b[N],c[N],mi=1e18,ans,ma=-1e18,p,res;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    a[n+1]=a[n];
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--)
    {
        p=0;
        if(a[i]==a[i-1]) continue;
        for(int j=i;j>=1;j--)
        {
            p+=a[i]-a[j];
            if(p>m) break;
            else ans=max(ans,i-j+1);
        }
    }
    printf("%lld\n",ans);
}
