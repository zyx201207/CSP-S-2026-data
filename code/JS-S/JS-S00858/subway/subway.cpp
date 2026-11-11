#include<bits/stdc++.h>
using namespace std;

const int MAXN = 500 + 5, MAXM = 5e5 + 10;

struct Node
{
    int v;
    int w;
};

int k[MAXN], stations[MAXM];

vector<Node> roads[MAXM];
vector<Node> t[MAXN];
long long dis[1010][1010];

queue<int> qlist;

bool vis[1010];

void Dijkstra( int node )
{
    memset( dis, 0x3f3f3f3f, sizeof(dis) );
    memset( vis, false, sizeof(vis) );

    qlist.push( node );

    while( !qlist.empty() )
    {
        int x = qlist.front();
        qlist.pop();

        for(int i = 0; i < roads[x].size(); i++)
        {
            int v = roads[x][i].v;
            int w = roads[x][i].w;

            if( vis[v] == true ) continue;

            vis[v] = true;

            if( dis[node][v] > dis[node][x] + dis[x][v] )
            {
                dis[node][v] = dis[node][x] + dis[x][v];
            }

            qlist.push( v );
        }
    }
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    int c = 0, n = 0, m = 0, d = 0;
    int q = 0;
    int maxk = 0;

    cin >> c;
    cin >> n >> m >> d;
    cin >> q;

    for(int i = 1; i <= m; i++)
    {
        cin >> stations[i];
    }

    for(int i = 1; i <= n; i++)
    {
        cin >> k[i];

        maxk = max( maxk, k[i] );

        int k1 = 0, k2 = 0, time = 0;

        for(int j = 1; j <= k[i]; j++)
        {
            int v = 0, w = 0;

            cin >> v >> w;

            t[i].push_back( {v, w} );

            if( j == 1 )
            {
                k1 = v;
            }
            else
            {
                k2 = v;
            }

            time += w;
        }

        dis[k1][k2] = time;
        dis[k2][k1] = time;

        roads[k1].push_back( {k2, time} );
        roads[k2].push_back( {k1, time} );
    }

    for(int i = 1; i <= n; i++)
    {
        Dijkstra( i );
    }

    while( q -- )
    {
        int x = 0, y = 0;

        cin >> x >> y;

        cout << dis[x][y] + stations[x] + stations[y] << endl;
    }

    return 0;
}
