#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k[505],w[500005],a[505][20005],t[505][20005],minv;
bool vis[500005];
vector<pair<long long,long long>>g[500005];
void bfs(int x,int y)
{
    queue<pair<long long,long long> >Q;
    Q.push({x,w[x]+w[y]});
    vis[x]=1;
    while(!Q.empty())
    {
        pair<long long,long long>last=Q.front();
        Q.pop();
        if(last.first==y)
        {
            minv=min(minv,last.second);
        }
        for(auto v:g[last.first])
        {
            if(!vis[v.first])
            {
                Q.push({v.first,last.second+v.second});
                vis[v.first]=1;
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c;
    cin >> n;
    cin >> m;
    cin >> d;
    cin >> q;
    for(int i=1;i<=m;i++)
    {
        cin >> w[i];
    }
    for(long long i=1;i<=n;i++)
    {
        cin >> k[i];
        long long pa,pt;
        cin >> a[i][1] >> t[i][1];
        pa=a[i][1];
        pt=t[i][1];
        cin >> a[i][2] >> t[i][2];
        g[pa].push_back({a[i][2],t[i][1]+t[i][2]});
        pa=a[i][2];
        pt=t[i][2];
        for(long long j=3;j<=k[i];j++)
        {
            cin >> a[i][j] >> t[i][j];
            g[pa].push_back({a[i][j],t[i][j]});
            pa=a[i][j];
            pt=t[i][j];
        }
    }
    while(q--)
    {
        long long x,y;
        cin >> x >> y;
        minv=2e18;
        for(int i=1;i<=m;i++) vis[i]=0;
        bfs(x,y);
        cout << minv << endl;
    }
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
