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
int b[maxn];
int n,m;
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    n = read(),m = read();
    for(int i = 1;i<=n;++i)
    {
        a[i] = read();
    }
    int ans = 0;
    for(int i = 29;i>=0;--i)
    {
        int cnt = 0;
        int t = 1<<i;
        for(int j = 1;j<=n;++j)
        {
            if(a[j]&t)
            {
                b[++cnt] = a[j];
            }
        }
        if(cnt>=m)
        {
            ans += t;
            swap(a,b);
            n = cnt;
        }
    }
    printf("%lld\n",ans);
    return 0;
}