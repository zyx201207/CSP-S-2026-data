#include<bits/stdc++.h>
using namespace std;
#define int long long
int c , n , m , d , qq;
long long dis[10006];
bool vis[10006];
vector<pair<int ,int> > v[40000006];
priority_queue<pair<long long , int > , vector<pair<long long ,int> > ,greater<pair<long long , int> >  > q;
void dij(int aa)
{
    q.push({0,aa});
    while(!q.empty())
    {
        int now = q.top().second;long long len = q.top().first;q.pop();
        if (vis[now]) continue;
        vis[now] = 1;

        for (int i = 0 ; i < v[now].size() ; i++ )
        {
            if (!vis[v[now][i].first] && dis[v[now][i].first] > len + v[now][i].second)
            {
                dis[v[now][i].first] = len + v[now][i].second;
                q.push({dis[v[now][i].first],v[now][i].first});
            }
        }
    }
}
signed main()
{
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    cin >> c >> n >> m >> d >> qq;
    // m station n xian
    for (int i = 1 ; i <= n ; i++ )
    {
        int w;
        cin >> w;
        v[2*m+i].push_back({i+m,w});
        v[i+m+i].push_back({2*m,w});
    }
    for (int i = 1 ; i <= n ; i++ )
    {
        int k;cin >> k;
        for (int i = 1 ; i <= k ; i++ )
        {
            int u,w;
            cin >> u >> w;
            v[i+3*m].push_back({m+u,w});
            v[m+u].push_back({i+3*m,w});
        }
    }
    while(qq--)
    {
        for(int i = 1 ; i <= 4 * m ; i++ )
        {
            dis[i] = 1000000000000000000;
        }

        int aa ,bb;cin >> aa >> bb;
        dij(aa+2*m);
        cout << dis[bb] << "\n";

    }
    return 0;
}
