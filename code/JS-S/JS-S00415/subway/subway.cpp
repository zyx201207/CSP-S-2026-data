#include <bits/stdc++.h>
#define int long long 
#define in int
using namespace std;
int c,n,m,d,q1;
int w[600000];
vector <int> g[600];
vector <int> jxd[600];
vector <int> g1[600000];
vector <int> jxd1[600000];
int e,s;
int kf(int root1,int root2)
{
    for(int i=0;i<g1[root2].size();i++)
    {
        if(g1[root2][i]-m==root1) return jxd1[root2][i];
    }
    return 0;
}
int dj1(int root1,vector <int> ed)
{
    //cout << root1 << endl;
    pair <int,int> op;
    op.first=0;
    op.second=root1;
    priority_queue <pair<int,int>,vector <pair<int,int> >,greater<pair<int,int > > > q;
    vector <int> dis(600,1e18);
    q.push(op);
    while(!q.empty())
    {
        op=q.top();
        q.pop();
        int root=op.second;
        int sum=op.first;
        if(dis[root]<1e18) continue;
        dis[root]=sum;
        for(int i=0;i<g[root].size();i++)
        {
            if(dis[g[root][i]]<1e18) continue;
            pair <int,int> nx;
            nx.first=sum+jxd[root][i];
            nx.second=g[root][i];
            q.push(nx);
        }
    }
    int sum=1e18;
    for(int i=0;i<ed.size();i++)
    {
        sum=min(sum,dis[ed[i]]+kf(ed[i],e)+kf(root1,s));
        //if(dis[ed[i]]+kf[ed[i]][e]==14) cout << dis[ed[i]] << endl;
    }
    return sum;
}
int dj(vector <int> sn,vector <int> ed)
{
    int ans=1e18;
    for(int i=0;i<sn.size();i++)
    {
        ans=min(dj1(sn[i],ed),ans);
    }
    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q1;
    for(int i=1;i<=m;i++)
    {
        cin >> w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin >> k;
        for(int j=1;j<=k;j++)
        {
            int u,v;
            cin >> u >> v;
            g1[u].push_back(i+m);
            jxd1[u].push_back(v);
            g1[i+m].push_back(u);
            jxd1[i+m].push_back(v);
        }
    }
    for(int root=1;root<=m;root++)
    {
        for(int i=0;i<g1[root].size();i++)
        {
            for(int j=0;j<g1[root].size();j++)
            {
                int root1=g1[root][i]-m;
                int root2=g1[root][j]-m; 
                if(root1==root2) continue;
                //if(root==2&&root1==1&&root2==2) cout << 114514 << endl;
                g[root1].push_back(root2);
                jxd[root1].push_back(jxd1[root][i]+jxd1[root][j]);
                /*g[root2].push_back(root1);
                jxd[root2].push_back(jxd1[root][i]+jxd1[root][j]);*/
            }
        }
        //cout << endl;
        /*for(int i=0;i<g[root].size();i++)
        {
            cout << root << " " << g[root][i] << " " << jxd[root][i] << endl;
        }*/
    }
    //cout << g[1][0] << endl;
    while(q1--)
    {
        cin >> s >> e;
        vector <int> sn;
        vector <int> ed;
        for(int i=0;i<g1[s].size();i++)
        {
            sn.push_back(g1[s][i]-m);
        }
        for(int i=0;i<g1[e].size();i++)
        {
            ed.push_back(g1[e][i]-m);
        }
        int ans=dj(sn,ed);
        ans=ans+w[e]+w[s];
        cout << ans << "\n";
    }

    return 0;
}