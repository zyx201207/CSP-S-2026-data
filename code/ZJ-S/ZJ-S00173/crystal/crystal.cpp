#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define gc getchar_unlocked
#define debug(num) printf("%s:%lld\n",#num,num)
inline int read()
{
    int x = 0,f = 1;
    char ch = gc();
    while(!isdigit(ch))
    {
        if(ch == '-') f = -1;
        ch = gc();
    }
    while(isdigit(ch))
    {
        x = (x<<3)+(x<<1)+(ch^'0');
        ch = gc();
    }
    return x*f;
}
constexpr int maxn = 5e5+10;
int a[maxn];
int n,m;
int calc(int t)
{
    int cnt = 0;
    int res = 0;
    for(int i = t;i>=1;--i)
    {
        int cost = a[t]-a[i];
        if(cnt+cost<=m)
        {
            ++res;
            cnt += cost;
        }
    }
    return res;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n = read(),m = read();
    for(int i = 1;i<=n;++i)
    {
        a[i] = read();
    }
    sort(a+1,a+n+1);
    int ans = 0;
    int cost = 0;
    a[0] = a[1];
    for(int l = 1,r = 1;r<=n;++r)
    {
        cost += (r-l+1)*(a[r]-a[r-1]);
        while(cost>m&&l<r)
        {
            cost -= a[r]-a[l];
            ++l;
        }
        ans = max(ans,r-l+1);
    }
    ++ans;
    printf("%lld\n",ans);
    return 0;
}