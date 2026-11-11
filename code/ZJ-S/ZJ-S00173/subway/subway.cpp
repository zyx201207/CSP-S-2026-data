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
using pii = pair<int,int>;
constexpr int inf = LLONG_MAX>>1;
constexpr int maxn = 5e2+10;
constexpr int maxm = 5e5+10;
constexpr int maxv = 6e5+10;
constexpr int maxq = 1e5+10;
int c,n,m,d,q;
int w[maxm];
vector<pii>gra[maxv];
int xldis[maxn][maxn];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c = read(),n = read(),m = read(),d = read(),q = read();
    for(int i = 1;i<=m;++i)
    {
        w[i] = read();
    }
    for(int i = 1;i<=n;++i)
    {
        int k = read();
        for(int j = 1;j<=k;++j)
        {
            int a = read(),t = read();
            gra[m+i].push_back({a,t});
            gra[a].push_back({m+i,t});
        }
    }
    for(int i = 1;i<=n;++i)
    {
        fill(xldis[i]+1,xldis[i]+n+1,inf);
        xldis[i][i] = 0;
        for(auto e1:gra[m+i])
        {
            int v = e1.first;
            int w = e1.second;
            for(auto e2:gra[v])
            {
                int v2 = e2.first;
                int w2 = e2.second;
                if(v2 == i+m) continue;
                xldis[i][v2-m] = min(xldis[i][v2-m],w+w2);
            }
        }
    }
    for(int k = 1;k<=n;++k)
    {
        for(int i = 1;i<=n;++i)
        {
            for(int j = 1;j<=n;++j)
            {
                xldis[i][j] = min(xldis[i][j],xldis[i][k]+xldis[k][j]);
            }
        }
    }
    for(int i = 1;i<=q;++i)
    {
        int x = read(),y = read();
        int ans = LLONG_MAX>>1;
        for(auto e1:gra[x])
        {
            int v = e1.first;
            int w = e1.second;
            for(auto e2:gra[y])
            {
                int v2 = e2.first;
                int w2 = e2.second;
                ans = min(ans,w+w2+xldis[v-m][v2-m]);
            }
        }
        ans += w[x]+w[y];
        printf("%lld\n",ans);
    }
    return 0;
}