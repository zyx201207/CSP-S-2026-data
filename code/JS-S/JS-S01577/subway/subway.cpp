#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node
{
    int id,t;
};
struct Edge
{
    int to,w;
};
int c,n,m,d,q;
int t1,t2;
int w[500005],k[500005];
vector<int> a[505],t[505];
int len[505][505];
int f[505][505];
vector<Node> v[500005];
vector<Edge> e[505];
void dij(int st)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > > q;
    q.push(make_pair(0,st));
    bool vis[505]={0};
    int d[505];
    memset(d,0x3f,sizeof(d));
    d[st]=0;
    while(q.size()!=0)
    {
        int now=q.top().second;
        q.pop();

        if(vis[now]==1)
        {
            continue;
        }
        vis[now]=1;
        for(int i=0;i<e[now].size();i++)
        {
            int nx=e[now][i].to;
            if(d[nx]>d[now]+e[now][i].w)
            {
                d[nx]=d[now]+e[now][i].w;
                q.push(make_pair(d[nx],nx));
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        f[st][i]=d[i];
    }
    return;
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    memset(len,0x3f,sizeof(len));
    for(int i=1;i<=n;i++)
    {
        len[i][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        a[i].push_back(0);
        t[i].push_back(0);
        for(int j=1;j<=k[i];j++)
        {
            cin>>t1>>t2;
            a[i].push_back(t1);
            t[i].push_back(t2);
            v[a[i][j]].push_back((Node){i,t[i][j]});//cout<<a[i][j]<<endl;
            int ed=v[a[i][j]].size()-1;
            for(int l=0;l<v[a[i][j]].size()-1;l++)
            {
                t1=v[a[i][j]][ed].id;
                t2=v[a[i][j]][l].id;
                len[t1][t2]=len[t2][t1]=min(len[t1][t2],v[a[i][j]][ed].t+v[a[i][j]][l].t);
                //cout<<ed<<" "<<l<<" "<<v[a[i][j]][ed].t+v[a[i][j]][l].t<<endl;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            if(len[i][j]<=1e17)
            {
                e[i].push_back((Edge){j,len[i][j]});
                e[j].push_back((Edge){i,len[i][j]});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        dij(i);
    }
    /*for(int l=1;l<=n;l++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                f[i][j]=min(f[i][j],f[i][l]+f[l][j]);
            }
        }
    }*/
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }*/
    while(q--)
    {
        cin>>t1>>t2;
        int ans=1e17;
        for(int i=0;i<v[t1].size();i++)
        {
            for(int j=0;j<v[t2].size();j++)
            {
                ans=min(ans,f[v[t1][i].id][v[t2][j].id]+v[t1][i].t+v[t2][j].t);
            }
        }
        cout<<ans+w[t1]+w[t2]<<'\n';
    }

    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<len[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
//diff subway.out subway4.ans
