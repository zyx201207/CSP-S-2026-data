#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[1000010],dis[100050],cnt[100050],vis[1000010];
long long jdz(long long x)  { return x > 0 ? x : -x; }
struct node
{
    long long to,w;
    bool operator < (const node& x) const { return w > x.w; }
};
vector <node> e[10050];
void dj(int start)
{
    for(int i = 1;i <= n;i++) dis[i] = 1e16,cnt[i] = 0,vis[i] = 0;
    priority_queue <node> q;
    dis[start] = 0;
    q.push({start,0});
    cnt[start] = 1;
    while(!q.empty())
    {
        long long u = q.top().to;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto v : e[u])
            if(dis[u] + v.w == dis[v.to])
            {
                cnt[v.to] += cnt[u];
            }
            else if(dis[u] + v.w < dis[v.to])
            {
                dis[v.to] = dis[u] + v.w;
                q.push({v.to,dis[v.to]});
                cnt[v.to] = 1;
            }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i = 1;i <= n;i++) cin>>a[i];
        for(long long i = 1;i <= n;i++)
            for(long long j = 1;j <= n;j++)
                if(jdz(a[j] - a[i]) <= d)
                    e[i].push_back({j,1});
        long long ans = 0;
        for(int i = 1;i <= n;i++)
        {
            dj(i);
            for(int j = i + 1;j <= n;j++) cout<<dis[j]<<" ",ans += (cnt[j] == 2);
            cout<<endl;
        }
        cout<<ans<<endl;
        for(int i = 1;i <= n;i++) e[i].clear();
    }
    return 0;
}
