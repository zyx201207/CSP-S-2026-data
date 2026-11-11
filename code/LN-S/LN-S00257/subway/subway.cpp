#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long xx,yy;
long long w[500005];
long long num;
long long g[505][505];
long long ans;
struct node
{
	long long line;
	long long to_hall;
};
long long p;
long long t_h;
int line_a,line_b;
long long th_a,th_b;
vector <node> station[500005];
int idx,idy;
void add_edge(int x)
{
	for(int i=0;i<(int)station[x].size();i++)
	{
		for(int j=i+1;j<(int)station[x].size();j++)
		{
			line_a = station[x][i].line;
			line_b = station[x][j].line;
			th_a = station[x][i].to_hall;
			th_b = station[x][j].to_hall;
			g[line_a][line_b] = min(g[line_a][line_b],th_a + th_b);
			g[line_b][line_a] = min(g[line_b][line_a],th_a + th_b);
		}
	}
}
bool if_same_line(int a,int b)
{
	for(int i=0;i<(int)station[a].size();i++)
	{
		for(int j=0;j<(int)station[b].size();j++)
		{
			if(station[a][i].line == station[b][j].line)
			{
				idx = i;
				idy = j;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
			cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			g[i][j] = LLONG_MAX / 2 - 1;
		}
	}//init
	for(int i=1;i<=n;i++)
	{
		cin>>num;
		for(int j=1;j<=num;j++)
		{
			cin>>p>>t_h;
			station[p].push_back({i,t_h});
		}
	}//input
	for(int i=1;i<=n;i++)
	{
		add_edge(i);
	}//create graph
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(g[i][j] > g[i][k] + g[k][j])
				{
					g[i][j] = g[i][k] + g[k][j];
				}
			}
		}
	}//floyd
	for(int i=1;i<=q;i++)
	{
		cin>>xx>>yy;
		if(if_same_line(xx,yy))
		{
			ans = w[xx] + w[yy];
			ans += station[xx][idx].to_hall;
			ans += station[yy][idy].to_hall;
			cout<<ans<<"\n";
			continue;
		}
		ans = LLONG_MAX;
		for(int i=0;i<(int)station[xx].size();i++)
		{
			for(int j=0;j<(int)station[yy].size();j++)
			{
				line_a = station[xx][i].line;
				line_b = station[yy][j].line;
				th_a = station[xx][i].to_hall;
				th_b = station[yy][j].to_hall;
				if(ans > g[line_a][line_b] + th_a + th_b)
				{
					ans = min(ans,g[line_a][line_b] + th_a + th_b);
				}
			}
		}
		ans += w[xx];
		ans += w[yy];
		cout<<ans<<"\n";
	}
	return 0;
}
