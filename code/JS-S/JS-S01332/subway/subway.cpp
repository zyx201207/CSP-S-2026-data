#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,idx,k,a,st,ed;
long long t,w[500005],dis[500005],ans[500005];
struct node
{
    int idx;
    long long val;
};
struct tap
{
    int id,l,r;
    bool operator<(const tap t) const
    {
        return l < t.l;
    }
}h[100005];
vector <node> s[500505];
void Dij(int st)
{
    memset(dis,0x3f3f3f3f,sizeof dis);
    queue <int> q;
    q.push(st);dis[st] = 0;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for (int i = 0; i < s[p].size(); i++)
            if (dis[s[p][i].idx] - s[p][i].val > dis[p])
                dis[s[p][i].idx] = dis[p] + s[p][i].val,
                q.push(s[p][i].idx);
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for (int i = 1; i <= m; i++)
        scanf("%lld",&w[i]);
    idx = m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&k);
        ++idx;
        for (int j = 1; j <= k; j++)
        {
            scanf("%d%lld",&a,&t);
            s[a].push_back({idx,t});
            s[idx].push_back({a,t});
        }
    }
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d",&st,&ed);
        if (st > ed)
            swap(st,ed);
        h[i] = {i,st,ed};
        ans[i] = w[st] + w[ed];
    }
    sort(h + 1,h + q + 1);
    for (int i = 1; i <= q; i++)
    {
        Dij(h[i].l);
        for (int j = i; j; j++)
            if (j > q || h[j].l != h[i].l)
            {

                i = j - 1;
                break;
            }
            else
                ans[h[j].id] += dis[h[j].r];
        }
    for (int i = 1; i <= q; i++)
            printf("%lld\n",ans[i]);
    return 0;
}
