#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int c, n, m, d, q;
int k;
int w[500];
int t[25][500];
int a[25][500];
vector<int> E[500];
ll dist[500];
bool vis[500];
void dij(int s)
{
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> pq;
    fill(vis+1,vis+1+m,false);
    fill(dist+1,dist+1+m,1e9);
    dist[s] = 0;
    pq.push({0,s});
    while(!pq.empty())
    {
        auto[d,u] = pq.top();
        pq.pop();
        if(vis[u])
            continue;
        vis[u] = true;
        for(auto v : E[u])
        {
            for(int id=0;id<k;id++)
            {
                int to = a[v][id];
                int weight = t[v][u] + t[v][id];
                if(dist[to] > dist[u] + weight)
                {
                    dist[to] = dist[u] + weight;
                    pq.push({dist[to],to});
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)
        cin >> w[i];
    for(int i=0;i<n;i++)
    {
        cin>>k;
        for(int j=0;j<k;j++)
        {
            cin>>a[i][j]>>t[i][j];
            E[j].push_back(i);
        }
    }
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        dij(x);
        cout<<dist[y] + w[x] + w[y]<<endl;
    }
    //fcolse(stdin);
    //fcolse(stdout);
    return 0;
}

