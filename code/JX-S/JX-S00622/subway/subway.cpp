#include<bits/stdc++.h>
using namespace std;
#define int long long
int w[500010],t[501][501];
int v[501];
vector<int>e[501];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;cin>>k;int u,v,t1,t2;
        cin>>u>>t1>>v>>t2;t[u][v]=t[v][u]=t1+t2;
        e[v].push_back(u);
        e[u].push_back(v);
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        priority_queue<int>q;
        q.push(x);v[x]=w[x];
        memset(v,0,sizeof v);
        while(q.size())
        {
            int tp=q.top();q.pop();
            if(tp==y)break;
            for(int x:e[tp])
            {
                if(v[x])continue;
                q.push(x);
                v[x]=v[tp]+t[tp][x];
            }
        }
        cout<<v[y]+w[y]<<'\n';
    }
return 0;
}
/*++rp*/
