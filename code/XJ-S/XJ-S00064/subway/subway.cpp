#include<iostream>
#include<vector>
using namespace std;
int w[5005];
int a[5005][205];
int t[5005][205],ans,k[5005],n;
vector<pair<int,int> > e[5000005];
void dfs(int u,int ed,int sum,int fa,int ff)
{
    if(sum>=ans)
    {
        return ;
    }
    if(u==ed)
    {
        ans=min(ans,sum);
        return ;
    }
    int l=e[u].size();
    for(int i=0;i<l;i++)
    {
        int v=e[u][i].first,w=e[u][i].second;
        if(v==fa)
        {
            continue;
        }
        if(v<=n&&ff==v)
        {
            continue;
        }
        if(v<=n)
        {
            dfs(v,ed,sum+t[v][v],u,v);
        }
        else
        {
            dfs(v,ed,sum+w,u,ff);
        }
    }
    return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
            e[i].push_back({n+a[i][j],t[i][j]});
            e[n+a[i][j]].push_back({i,t[i][j]});
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        ans=0x7f7f7f7f;
        dfs(x,n+y,w[x]+w[y]+t[x][x],-1,x);
        cout<<ans<<endl;
    }
	return 0;
} 