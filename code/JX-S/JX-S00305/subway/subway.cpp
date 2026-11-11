#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],k[510],x[100010],y[100010],tt1[500010],tt2[500010],a1[500010],a2[500010],a3[500010];
long long ans;
vector<int>t[510];
vector<int>s[500010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	//c 测试点编号   若 c = 0,则该测试点为样例
	//n 地铁线路数   500
	//m 地铁站数     5 × 1e5
	//d 每个地铁站最多被几条线路经过 20
	//q 出行计划数   1e5
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
		//从每个地铁站的地铁口走到站厅需要的时间
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int e,f;
			cin>>e>>f;
			if(i==1)
			{
				a1[e]=f;
			}
			if(i==2)
			{
				a2[e]=f;
			}
			if(i==3)
			{
				a3[e]=f;
			}
			//ai[j] j地铁站到第i条线路需要的时间
		}
	}
	if(n==1)
	{
		for(int r=1;r<=q;r++)
		{
			cin>>x[r]>>y[r];
			//起点地铁站编号
			//终点地铁站编号
			cout<<w[x[r]]+w[y[r]]+a1[x[r]]+a1[y[r]]<<"\n";
		}
		return 0;
	}
	if(n==2)
	{
		for(int r=1;r<=q;r++)
		{
			int ans=2000000010;
			cin>>x[r]>>y[r];
			//起点地铁站编号
			//终点地铁站编号
			for(int i=1;i<=m;i++)
			{
				if(a1[i]&&a1[x[r]])
				{
					
					if(!tt1[i])
					{
						tt1[i]=a1[i]+a1[x[r]];
					}
					else
					{
						tt1[i]=min(tt1[i],a1[i]+a1[x[r]]);
					}
				}
				if(a2[i]&&a2[x[r]])
				{
					if(!tt1[i])
					{
						tt1[i]=a2[i]+a2[x[r]];
					}
					else
					{
						tt1[i]=min(tt1[i],a2[i]+a2[x[r]]);
					}
				}
				if(a1[i]&&a1[y[r]])
				{
					if(!tt2[i])
					{
						tt2[i]=a1[i]+a1[y[r]];
					}
					else
					{
						tt2[i]=min(tt2[i],a1[i]+a1[y[r]]);
					}
				}
				if(a2[i]&&a2[y[r]])
				{
					if(!tt2[i])
					{
						tt2[i]=a2[i]+a2[y[r]];
					}
					else
					{
						tt2[i]=min(tt2[i],a2[i]+a2[y[r]]);
					}
				}
			}
			if(a1[x[r]]&&a1[y[r]])
			{
				ans=a1[x[r]]+a1[y[r]];
			}
			if(a2[x[r]]&&a2[y[r]])
			{
				ans=min(ans,a2[x[r]]+a2[y[r]]);
			}
			for(int i=1;i<=m;i++)
			{
				if(!tt1[i]||!tt2[i]||i==x[r]||i==y[r])
				{
					continue;
				}
				ans=min(ans,tt1[i]+tt2[i]);
			}
			ans+=w[x[r]]+w[y[r]];
			cout<<ans<<"\n";
		}
		return 0;
	}
	if(n==3)
	{
		for(int r=1;r<=q;r++)
		{
			int ans=2000000010;
			cin>>x[r]>>y[r];
			//起点地铁站编号
			//终点地铁站编号
			for(int i=1;i<=m;i++)
			{
				if(a1[i]&&a1[x[r]])
				{
					
					if(!tt1[i])
					{
						tt1[i]=a1[i]+a1[x[r]];
					}
					else
					{
						tt1[i]=min(tt1[i],a1[i]+a1[x[r]]);
					}
				}
				if(a2[i]&&a2[x[r]])
				{
					if(!tt1[i])
					{
						tt1[i]=a2[i]+a2[x[r]];
					}
					else
					{
						tt1[i]=min(tt1[i],a2[i]+a2[x[r]]);
					}
				}
				if(a3[i]&&a3[x[r]])
				{
					if(!tt1[i])
					{
						tt1[i]=a3[i]+a3[x[r]];
					}
					else
					{
						tt1[i]=min(tt1[i],a3[i]+a3[x[r]]);
					}
				}
				if(a1[i]&&a1[y[r]])
				{
					if(!tt2[i])
					{
						tt2[i]=a1[i]+a1[y[r]];
					}
					else
					{
						tt2[i]=min(tt2[i],a1[i]+a1[y[r]]);
					}
				}
				if(a2[i]&&a2[y[r]])
				{
					if(!tt2[i])
					{
						tt2[i]=a2[i]+a2[y[r]];
					}
					else
					{
						tt2[i]=min(tt2[i],a2[i]+a2[y[r]]);
					}
				}
				if(a3[i]&&a3[y[r]])
				{
					if(!tt2[i])
					{
						tt2[i]=a3[i]+a3[y[r]];
					}
					else
					{
						tt2[i]=min(tt2[i],a3[i]+a3[y[r]]);
					}
				}
			}
			if(a1[x[r]]&&a1[y[r]])
			{
				ans=a1[x[r]]+a1[y[r]];
			}
			if(a2[x[r]]&&a2[y[r]])
			{
				ans=min(ans,a2[x[r]]+a2[y[r]]);
			}
			if(a3[x[r]]&&a3[y[r]])
			{
				ans=min(ans,a3[x[r]]+a3[y[r]]);
			}
			for(int i=1;i<=m;i++)
			{
				if(!tt1[i]||!tt2[i]||i==x[r]||i==y[r])
				{
					continue;
				}
				ans=min(ans,tt1[i]+tt2[i]);
			}
			ans+=w[x[r]]+w[y[r]];
			cout<<ans<<"\n";
		}
		return 0;
	}
	return 0;
}
