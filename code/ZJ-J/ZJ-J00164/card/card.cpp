#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=5e5+10;
constexpr int maxm=3e5+10;
constexpr int maxB=30+10;
int n,m,ans,a[maxn],last[maxm],cnt[maxm],rd[maxm];
vector<int>gra[maxm];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
        last[a[i]]=i;
        ++cnt[a[i]];
    }
    for(int i=1;i<=m;++i)
    {
        int p=last[i];
        if(p!=n)
        {
            gra[i].emplace_back(a[p+1]);
            ++rd[a[p+1]];
        }
    }
    queue<int>q;
    for(int i=1;i<=m;++i)
    {
        if(!rd[i])
        {
            q.emplace(i);
        }
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:gra[u])
        {
            cnt[v]+=cnt[u];
            if(!--rd[v])
            {
                q.emplace(v);
            }
        }
    }
    for(int i=1;i<=m;++i)
    {
        printf("%lld ",cnt[i]);
    }
    return 0;
}
