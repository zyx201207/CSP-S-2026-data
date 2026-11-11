#include<bits/stdc++.h>
using namespace std;
#define inf 0x37373737
const int N=505,M=1005;
int w[M];
struct node{
    int v,w;
} ;
map<int,int> g[M];
int c, n, m, d, q;
queue<int> p;
bool v[M];
int x[M];
void bfs(int s)
{
    while (!p.empty())
    {
        p.pop();
    }
    for(int i=1;i<=n;i++)
    {
        v[i]=0;
        x[i]=inf;
    }
    v[s]=1;
    x[s]=0;
    p.push(s);
    while (!p.empty())
    {
        int y=p.front();
        p.pop();
        for(auto b:g[y])
        {
            if(!v[b.first]) p.push(b.first);
            x[b.first]=min(x[b.first],b.second+x[y]);
        }
    }
    
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        vector<node> l;
        l.clear();
        for(int j=1;j<=k;j++)
        {
            int v,e;
            cin>>v>>e;
            
            for(auto b:l)
            {
                if(g[b.v][v]) 
                    g[b.v][v]=min(g[b.v][v],e+w[b.v]+b.w);
                else
                    g[b.v][v]=e+w[b.v]+b.w;
            }
            l.push_back({v,e});
        }
    }
    for(int u=1;u<=n;u++)
    {
        int s,e;
        cin>>s>>e;
        bfs(s);
        cout<<x[e]<<'\n';
    }
    return 0;
}