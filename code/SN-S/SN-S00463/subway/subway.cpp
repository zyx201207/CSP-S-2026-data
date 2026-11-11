/*
考号：SN-S00463
姓名：魏熙朝
学校：西安铁一中滨河高级中学
*/ 
#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,Q,w[500005],K,vis[505];//rjq表示两个线路间的最短换乘所需时间，guo表示第i个站点有哪些线路经过 
int rjq[505][505],ans;
vector<int>guo[500005],t[500005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
vector<pair<int,int> >G[505];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int A,T;
		cin>>K;
		for(int j=1;j<=K;j++)
		{
			cin>>A>>T;
			guo[A].push_back(i);
			t[A].push_back(T);
		}
	} 
//	for(int i=1;i<=m;i++)
//	{
//		cout<<i<<endl;
//		for(int j=0;j<guo[i].size();j++)
//		{
//			cout<<guo[i][j]<<" "<<t[i][j]<<"|";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{	
			if(i!=j)rjq[i][j]=rjq[j][i]=1e18;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<guo[i].size();j++)
		{
			for(int k=0;k<guo[i].size();k++)
			{
				if(guo[i][j]==guo[i][k])continue;
				rjq[guo[i][j]][guo[i][k]]=min(rjq[guo[i][j]][guo[i][k]],t[i][j]*1ll+t[i][k]);
				//cout<<rjq[j][k]<<endl;
				//G[guo[i][j]].push_back({})
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<rjq[i][j]<<" ";
//		}
//		cout<<"\n"; 
//	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			//cout<<i<<" "<<j<<" "<<rjq[i][j]<<endl;
			if(rjq[i][j]!=1e18&&i!=j)
			{
				G[i].push_back({rjq[i][j],j});
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<i<<"->";
//		for(int j=0;j<G[i].size();j++)
//		{
//			cout<<G[i][j].second<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++)
	{
		while(!q.empty())q.pop();
		for(int j=1;j<=n;j++)rjq[i][j]=1e18;
		for(int j=1;j<=n;j++)vis[j]=0;
		rjq[i][i]=0;
		q.push({rjq[i][i],i});
		while(!q.empty())
		{
			int now=q.top().second;
			q.pop();
			if(vis[now]==1)continue;
			vis[now]=1;
			for(int j=0;j<G[now].size();j++)
			{
				pair<int,int>nxt=G[now][j];
				if(rjq[i][nxt.second]>rjq[i][now]+nxt.first)
				{
					rjq[i][nxt.second]=rjq[i][now]+nxt.first;
					q.push({rjq[i][nxt.second],nxt.second});
				}
			}
		}
	}
//	for(int i=2;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			for(int k=1;k<=n;k++)
//			{
//				if(j==k)continue;
//				for(int y=1;y<=n;y++)
//				{
//					rjq[j][k]=min(rjq[j][k],rjq[j][y]+rjq[y][k]);
//				}
//			}
//		}
//	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<rjq[i][j]<<" ";
//		}
//		cout<<"\n"; 
//	}
	while(Q--)
	{
		int u,v;
		cin>>u>>v;
		ans=1e18;
		for(int i=0;i<guo[u].size();i++)
		{
			for(int j=0;j<guo[v].size();j++)
			{
				if(guo[u][i]==guo[v][j])ans=min(ans,t[u][i]*1ll+t[v][j]);
				ans=min(ans,rjq[guo[u][i]][guo[v][j]]+t[u][i]+t[v][j]);
			}
		}
		ans+=w[u]+w[v];
		cout<<ans<<"\n";
	}
	return 0;
}

