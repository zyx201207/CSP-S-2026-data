#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int w[501],b[501],dis[501][501],c,n,m,d,q;;//izhantai ?zouguo
struct stu
{
        int v,w;
};
vector<stu> g[500101];
void bfs(int x)
{
    memset(b,false,sizeof(b));
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,x});
    b[x] = true;
    while (!q.empty())
    {
        pii d = q.top();
        q.pop();
        if (d.second <= n)
        {
             dis[x][d.second] = min(dis[x][d.second],d.first);
        }
        for (auto j:g[d.second])
        {
            if (j.v > n || !b[j.v])
            {
                q.push({d.first+j.w,j.v});
                b[j.v] = true;
            }
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> m >> n >> d >> q;
    for (int i = 1;i<=n;i++)
    {
        cin >> w[i];
    }
    for (int i = 1;i<=m;i++)
    {
        int t;
        cin >> t;
        for (int j = 1;j<=t;j++)
        {
            int v,w;
            cin >> v >> w;
            g[v].push_back({n+i,w});
            g[n+i].push_back({v,w});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for (int i = 1;i<=n;i++)
    {
        bfs(i);
    }
    while (q--)
    {
        int x,y;
        cin >> x >> y;
        cout << dis[x][y]+w[x]+w[y] << "\n";
    }
    return 0;
}
