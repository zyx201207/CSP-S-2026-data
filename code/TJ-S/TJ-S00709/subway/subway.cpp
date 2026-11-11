#include<bits/stdc++.h>
using namespace std;
int m,n,q,d,c;
struct pic{
	int v;//从门口到车站时间
	int t[505];//t[i]表示到第i号路线的时间 
}a[500005];
struct road{
	int v,s;//v代表下一站s代表线路
};
vector<road> g[505];//g[i][j]:i->j
//bool rea=false;
int dfs(int x/*所处车站*/,int y/*目标车站*/,int sum/*所耗时间*/,int from/*所来车站*/)
{
	if(x==y)
	{
		//rea=true;
		sum+=a[x].v;
		return sum;
	}
	int ans=1e9;
	sum+=a[x].v;
	int ws=g[x].size();
	for(int w=0;w<ws;w++)
	{
		if(g[x][w].s==from)
		{
			continue;
		}
		int ss=dfs(g[x][w].v,y,sum+a[g[x][w].s].v,g[x][w].s);
		//if(rea)
		//{
			ans=min(ans,ss);
		//	rea=false;
		//}
	}
	return ans;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].v;
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		vector<int> y;
		for(int j=1;j<=k;j++)
		{
			int x,t;
			cin>>x;
			int ws=y.size();
			for(int w=0;w<ws;w++)
			{
				g[x].push_back({y[w],i});
				g[y[w]].push_back({x,i});
			}
			cin>>a[x].t[i];
			y.push_back(x);
		} 
	}
	int ans=1e9;
	for(int www=1;www<=q;www++)
	{
		int x,y;
		cin>>x>>y;
		cout<<dfs(x,y,0,0)<<endl;
	}
	return 0;
}
