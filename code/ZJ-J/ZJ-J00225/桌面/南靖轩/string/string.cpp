#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=2e5+10;
int n;
int a[maxn];
char c[maxn];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld %c",a+i,c+i);
    }
    int l=1,r=n,res=0;
    while(l<r)
    {
        if(c[l]!=c[r]) 
        {
            res+=min(a[l],a[r]);
            int tmp=min(a[l],a[r]);
            a[l]-=tmp;
            a[r]-=tmp;
            if(!a[l]) ++l;
            if(!a[r]) --r;
        }
        else
        {
            int tmp=min(a[l],a[r]);
            a[l]-=tmp;
            a[r]-=tmp;
            if(!a[l]) ++l;
            if(!a[r]) --r;
        }
    }
    printf("%lld",res);
    return 0;
}