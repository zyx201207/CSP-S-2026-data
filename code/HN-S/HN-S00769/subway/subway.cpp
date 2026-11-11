#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,Q,w[500010],k[510],a,t,x,y,dis[510],vis[510],minn,lc;
struct ll
{
	int to,v;
	bool operator<(const ll &X)const
	{
		return X.v<v;
	}
};
vector<ll> t2[500010];
vector<ll> e[510];
priority_queue<ll> q;
inline void dij(int st)
{
	q.push({st,0});
	dis[st]=0;
	while(!q.empty())
	{
		ll nt=q.top();
//		cout<<nt.to<<" "<<nt.v<<"\n";
		q.pop();
		if(vis[nt.to])
		{
			continue; 
		}
		vis[nt.to]=1;
		for(int i=0;i<e[nt.to].size();i++)
		{
			ll V=e[nt.to][i];
			dis[V.to]=min(dis[V.to],nt.v+V.v);
			q.push({V.to,dis[V.to]});
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a>>t;
			if(t2[a].empty())
			{
				t2[a].push_back({i,t});
			}
			else
			{
				for(int o=0;o<t2[a].size();o++)
				{
//					cout<<t2[a][o].to<<" "<<i<<" "<<a<<" "<<t<<" "<<t2[a][o].v<<"\n";
					e[t2[a][o].to].push_back({i,t2[a][o].v+t});
					e[i].push_back({t2[a][o].to,t2[a][o].v+t});
//					cout<<e[2][0].to<<" "<<e[2][0].v<<"\n";
//					cout<<e[1][0].to<<" "<<e[1][0].v<<"\n";
				}
				t2[a].push_back({i,t});
			}
		}
	}
	while(Q--)
	{
		cin>>x>>y;
		int f=0,sum=INT_MAX;
		for(int i=0;i<t2[x].size();i++)
		{
			for(int j=0;j<t2[y].size();j++)
			{
				if(t2[x][i].to==t2[y][j].to)
				{
					f=1;
					sum=min(sum,t2[x][i].v+t2[y][j].v);
					break;
				}
			}
		} 
		if(f==1)
		{
			cout<<sum+w[x]+w[y]<<"\n";
			continue;
		}
		minn=INT_MAX;
		for(int i=0;i<t2[x].size();i++)
		{
			for(int i=1;i<=500;i++)
			{
				dis[i]=INT_MAX;
				vis[i]=0;
			}
			lc=t2[x][i].to;
			dij(lc);
//			cout<<dis[1]<<" "<<dis[2]<<"\n";
			for(int j=0;j<t2[y].size();j++)
			{
				minn=min(minn,dis[t2[y][j].to]+t2[x][i].v+t2[y][j].v);
//				cout<<i<<" "<<j<<" "<<minn<<" "<<t2[x][i].v<<" "<<t2[y][j].v<<" "<<dis[t2[y][j].to]<<"\n";
			}
		} 
		cout<<minn+w[x]+w[y]<<"\n";
	}
	return 0;
}
//ccf我求你了别卡我,2.5e8应该不会炸吧？ 
//cnm，原来不是单源最短路，那有点炸了呀。。。。。。
//好像是个O(qn^2logn)的，而且常数超级无敌大！
//伟大的神告诉我，这题我过了他吃。
//那就只剩32pts了T_T 
