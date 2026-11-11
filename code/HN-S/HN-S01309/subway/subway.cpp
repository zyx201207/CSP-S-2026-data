#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e4 + 5000;
int c,n,m,d,q;
int w[N],point[N];
int vis[N];
int is_link[N][N];
struct Line
{
	int k;
	int a[N],t[N];
}the_line[505];

int dfs(int from,int to)
{
	int go_rich = 0;
	for(int i = 1;i <= m; i++)
	{
		if(is_link[from][i] == 1 && vis[i] == -1 && from != i)
		{
			vis[from] = 1;
			go_rich += point[i];
			if(i == to)
				return go_rich;
			else
				dfs(i,to);
		}
	}
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(vis,-1,sizeof(vis));	
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m; i++)
	{
		cin>>w[i];
	}
	for(int i = 1;i <= n; i++)
	{
		cin>>the_line[i].k;
		cin>>the_line[i].a[1]>>the_line[i].t[1];
		if(the_line[i].k > 1)
		{
			for(int j = 2;j <= the_line[i].k; j++)
			{
				cin>>the_line[i].a[j]>>the_line[i].t[j];
				point[the_line[i].a[j]] += the_line[i].t[j];
				is_link[the_line[i].a[j - 1]][the_line[i].a[j]] = 1;
				is_link[the_line[i].a[j]][the_line[i].a[j - 1]] = 1;
			}
		}
	}
	while(q--)
	{
		int x,y;
		int ans = 0;
		cin>>x>>y;
		ans += dfs(x,y);
		ans += point[x];
		ans = ans + w[x] + w[y];
		cout<<ans<<'\n';
	}
	return 0;
}
