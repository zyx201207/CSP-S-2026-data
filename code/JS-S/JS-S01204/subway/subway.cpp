#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 510;
const int M = 5e5 + 10;
const int INF = 1e9 + 7;
const int Q = 1e5 + 10;

int c,n,m,d,q;
vector<vector<pair<int,int>>> g(N);  //id,t
vector<pair<int,int>> p[M];    //id -> {g_id,t}

int path[N][N];
int relax[N][N];

int w[M];
int dis[M];
ll tot;

struct Node
{
    int st,ed,id;
};
Node qu[Q];
int ans[Q];

bool cmp(Node x,Node y)
{
    return x.st < y.st;
}
void sol(int x)
{
    for(int i = 1;i <= m;i++)
    {
        dis[i] = INF;
    }

    priority_queue<pair<int,int>> q;
    q.push({0,x});
    dis[x] = 0;

    while(!q.empty())
    {
        int nw = -q.top().first;
        int nx = q.top().second;
        q.pop();

        if(nw != dis[nx])
        {
            continue;
        }

        for(int i = 0;i < p[nx].size();i++)
        {
            int id = p[nx][i].first;
            int t = p[nx][i].second;

            for(int j = 0;j < g[id].size();j++)
            {
                tot++;
                int to = g[id][j].first;
                int w = g[id][j].second + t;
                if(to == nx)
                {
                    continue;
                }

                if(nw + w < dis[to])
                {
                    dis[to] = dis[nx] + w;
                    q.push({-dis[to],to});
                }
            }
        }
    }

 //   return dis[y] + w[x] + w[y];
}

void sol_2(int x,int y)
{
    if(p[x].size() == 1 && p[y].size() == 1)
    {
        if(p[x][0].first == p[y][0].first)
        {
            dis[y] = p[x][0].second + p[y][0].second;
        }
        else
        {

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

    for(int i = 1;i <= m;i++)
    {
        cin >> w[i];
    }

    int flag = 0;
    for(int i = 1;i <= n;i++)
    {
        int x,k,t,lt;
        cin >> k;
        for(int j = 1;j <= k;j++)
        {
            lt = t;
            cin >> x >> t;

            if(lt != t)
            {
                flag = 1;
            }

            g[i].push_back({x,t});
            p[x].push_back({i,t});
        }
    }

    int cnt = 0;
    while(q--)
    {
        int x,y;
        cin >> x >> y;

 //       ans = sol(x,y);

        cnt++;
        qu[cnt] ={x,y,cnt};
 //       cout << "ans: ";
  //      cout << ans <<endl;
    }



        sort(qu + 1,qu + cnt + 1,cmp);

        for(int i = 1;i <= cnt;i++)
        {
            int x = qu[i].st;
            int y = qu[i].ed;
            if(x != qu[i - 1].st)
            {
                sol(x);
            }
            ans[qu[i].id] = dis[y] + w[x] + w[y];
        }

        for(int i = 1;i <= cnt;i++)
        {
            cout << ans[i]<<endl;
        }
   // }

 //   }
 //   cout << tot <<endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

