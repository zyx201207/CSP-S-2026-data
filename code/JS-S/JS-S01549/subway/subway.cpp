#include <bits/stdc++.h>
using namespace std;

const int N=2e4+10;

struct node
{
    int to;
    long long val;
    int road;

    bool operator < (const node &a) const
    {
        return val>a.val;
    }
};

struct node1
{
    int to,road;
};

int c,n,m,d,q;
int t[500][N];
bool vis[500][N];
int w[N];
vector<node1> G[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;

    for(int i=1; i<=m; i++)
    {
        cin>>w[i];
    }


    for(int i=1; i<=n; i++)
    {
        int num;
        cin>>num;
        int last,lasttim;
        cin>>last>>lasttim;
        t[i][last]=lasttim;
        for(int j=1; j<num; j++)
        {
            int x,tim;
            cin>>x>>tim;
            G[x].push_back({last,i});
            G[last].push_back({x,i});
            t[i][x]=tim;
            last=x,lasttim=tim;
        }
    }

    while(q--)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                vis[i][j]=0;
            }
        }
        int x,y;
        cin>>x>>y;
        priority_queue<node> pq;
        for(int i=1; i<=n; i++)
        {
            if(t[i][x])
            {
                pq.push({x,t[i][x],i});
            }
        }
        while(!pq.empty())
        {
            node now=pq.top();
            pq.pop();

            if(now.to==y)
            {
                cout<<now.val+w[x]+w[y]+t[now.road][now.to]<<endl;
                break;
            }
            if(vis[now.road][now.to])
            {
                continue;
            }

            vis[now.road][now.to]=1;
            //dis1[x][now.to]=now.val;

            for(node1 a:G[now.to])
            {
                if(vis[a.road][a.to])
                {
                    continue;
                }
                if(a.road!=now.road)
                {
                    long long dis=now.val;
                    dis=dis+t[a.road][now.to]+t[now.road][now.to];
                    pq.push({a.to,dis,a.road});
                }
                else if(a.road==now.road)
                {
                    pq.push({a.to,now.val,now.road});
                }
            }
        }
    }

    return 0;
}
