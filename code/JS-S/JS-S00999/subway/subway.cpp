#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
    int to;
    int value;
};
int c,n,m,d,q;
queue<int> q1;
vector<node> g[500508];
ll dis[500508];
bool t[500508];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    vector<int> w(m+1);
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a,t;
            cin>>a>>t;
            g[a].push_back({m+i,t});
            g[m+i].push_back({a,t});
        }
    }
    while(q--)
    {
        while(!q1.empty()) q1.pop();
        int x,y;
        cin>>x>>y;
        int ans=w[x]+w[y];
        for(int i=1;i<=n+m;i++)
            dis[i]=4557430888798830399,t[i]=false;
        dis[x]=0;
        q1.push(x);t[x]=true;
        while(!q1.empty())
        {
            int u=q1.front();
            q1.pop();t[u]=false;
            for(node v:g[u])
            {
                int v1=v.to,w=v.value;
                if(dis[v1]>w+dis[u])
                {
                    dis[v1]=w+dis[u];
                    if(!t[v1])
                    {
                        q1.push(v1);
                        t[v1]=true;
                    }
                }
            }
        }
        cout<<dis[y]+ans<<endl;
    }
    return 0;
}
//zhetidenandianjiushijianmo
