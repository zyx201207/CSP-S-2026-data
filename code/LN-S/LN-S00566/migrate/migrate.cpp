#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,t,n,d;
int dis[N],ans[N],xx[N];
struct Edge
{
    int dis,v;
    bool operator <(Edge a) const { return dis>a.dis; }
};
vector< pair<int,int> > g[N];
void dij(int s)
{
	priority_queue<Edge> q;
    memset(dis,0x3f,sizeof dis);
    for (int i=1;i<=n;i++) ans[i]=1;
    dis[s]=0;
    q.push({0,s});
    while (!q.empty())
    {
        Edge t=q.top();
        q.pop();
        int x=t.v;
        for (auto e : g[x])
        {
            int y=e.first,w=e.second;
            if (dis[y]>dis[x]+w)
            {
                dis[y]=dis[x]+w;
                q.push({dis[y],y});
                ans[y]=1;
            }
            else if (dis[y]==dis[x]+w) ans[y]++;
        }
    }
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>c>>t;
    while (t--)
    {
		int sum=0;
        cin>>n>>d;
        for (int i=1;i<=n;i++) cin>>xx[i];
        for (int i=1;i<n;i++)
            for (int j=i+1;j<=n;j++)
                if (xx[j]-xx[i]<=d) g[i].push_back({j,(xx[j]-xx[i])});
        dij(1);
        for (int i=1;i<=n;i++) if (ans[i]==2) sum++;
        if (n-d==2 || d-n==2) sum--;
        cout<<sum<<"\n";
    }
    return 0;
}
