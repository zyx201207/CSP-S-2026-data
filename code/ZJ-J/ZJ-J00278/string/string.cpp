#include<bits/stdc++.h>

using namespace std;

#define int long long
#define uint unsigned long long
#define inf (LLONG_MAX>>1)

constexpr int maxn=2e5+10;

int n;
int a[maxn];
int c[maxn];

signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
    {
        char op[5];
        scanf("%lld",a+i);
        scanf("%s",op);
        c[i]=op[0]-'a';
    }
    int ans=0;
    for(int l=1,r=n;l<=r;)
    {
        if(c[l]==c[r])
        {
            int nd=min(a[l],a[r]);
            a[l]-=nd;
            if(l!=r) a[r]-=nd;
        }
        else
        {
            int nd=min(a[l],a[r]);
            ans+=nd;
            a[l]-=nd,a[r]-=nd;
        }
        if(!a[l]) ++l;
        if(!a[r]) --r;
    }
    printf("%lld\n",ans);
    return 0;
}