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
constexpr int maxn = 2e5+10;
int a[maxn];
char c[maxn];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n = read();
    for(int i = 1;i<=n;++i)
    {
        a[i] = read();
        c[i] = gc();
    }
    int j = n,i = 1;
    int ans = 0;
    while(i<j)
    {
        int t = min(a[i],a[j]);
        if(c[i] != c[j])
        {
            ans += t;
        }
        a[i] -= t;
        a[j] -= t;
        if(a[j] == 0) --j;
        if(a[i] == 0) ++i;
    }
    printf("%lld\n",ans);
    return 0;
}