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
int n,m;
int a[maxn];
int pos[maxn];
int cnt[maxn];
int ans[maxn];
int deg[maxn];
vector<int> gra[maxn];
void topo()
{
    queue<int> q;
    for(int i = 1;i<=m;++i)
    {
        if(pos[i]&&!deg[i])
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        ans[u] += cnt[u];
        for(int v:gra[u])
        {
            ans[v] += ans[u];
            if(!--deg[v]) q.push(v);
        }
    }
}
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    n = read(),m = read();
    for(int i = 1;i<=n;++i)
    {
        a[i] = read();
        ++cnt[a[i]];
        pos[a[i]] = i;
    }
    int last = 0;
    for(int i = n;i>=1;--i)
    {
        if(pos[a[i]] == i)
        {
            gra[a[i]].push_back(a[i+1]);
            ++deg[a[i+1]];
        }
    }
    topo();
    for(int i =1;i<=m;++i)
    {
        printf("%lld ",ans[i]);
    }
    return 0;
}