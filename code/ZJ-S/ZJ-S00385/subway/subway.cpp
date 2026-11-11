#include<bits/stdc++.h>
#define ll long long
#define PI pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=50005;
ll c,n,m,d,q,w[N],a[N],t[N],dis[1005][1005],k[505];
vector<ll>_a[505],_t[505];
bool flag1=1,flag2=1;
int T;
int u,v,_w;
void solve1()
{
//	cout<<"solve1"<<endl;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=m;++j)
		{
			if(i==j)
			{
				dis[i][j]=0;
			}
			else
			{
				dis[i][j]=1e18;
			}
		}
	int s;
	for(int i=1;i<=n;++i)
	{
		cin>>s;
//		cout<<i<<" "<<s<<endl;
		for(int j=1;j<=s;++j)
		{
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<s;++j)
		{
			for(int k=j+1;k<=s;++k)
			{
				dis[a[j]][a[k]]=min(dis[a[j]][a[k]],t[j]+t[k]);
				dis[a[k]][a[j]]=min(dis[a[k]][a[j]],t[j]+t[k]);
			}
		}
//		cout<<i<<"debug"<<endl;
	}
//	cout<<"debug"<<endl;
	for(int k=1;k<=m;++k)
		for(int i=1;i<=m;++i)
		{
			if(i==k)continue;
			for(int j=1;j<=m;++j)
			{
				if(i==j||j==k)continue;
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
//	cout<<"debug"<<endl;
	while(q--)
	{
		cin>>u>>v;
//		cout<<q<<" "<<u<<" "<<v<<endl;
		cout<<dis[u][v]+w[u]+w[v]<<"\n";
	}
	return ;
}
void solve2()
{
	vector<PI>g[1010];
	for(int i=1;i<=n;++i)
	{
		if(k[i]==2)
		{
			u=_a[i][0],v=_a[i][1],_w=_t[i][0]+_t[i][1];
			g[u].pb(make_pair(v,_w));
			g[v].pb(make_pair(u,_w));
		}
	}
	for(int i=1;i<=m;++i)
	{
		priority_queue<PI>pq;
		pq.push(make_pair(0,i));
		for(int j=1;j<=m;++j)
		{
			dis[i][j]=1e9;
		}
		while(pq.size())
		{
			PI now=pq.top();pq.pop();
			if(dis[i][now.se]<now.fi)
			{
				continue;
			}
			dis[i][now.se]=now.fi,u=now.se;
			if(now.se==v)
			{
				break;
			}
			for(PI tmp:g[u])
			{
				v=tmp.fi,_w=tmp.se;
				if(dis[i][v]>dis[i][u]+_w)
				{
					pq.push(make_pair(dis[i][u]+_w,v));
				}
			}
		}
	}
	while(q--)
	{
		cin>>u>>v;
		cout<<dis[u][v]+w[u]+w[v]<<"\n";
	}
	return ;
}
void solve3()
{
	bool _b[20010][505];
	ll _dis[20010],now;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)_b[j][i]=0;
		for(int j=1;j<=k[i];++j)
		{
			_b[_a[i][j-1]][i]=1;
		}
	}
//	q=1;
	while(q--)
	{
		cin>>u>>v;
		queue<int>q;
		for(int i=1;i<=m;++i)_dis[i]=1e18;
		q.push(u);_dis[u]=0;
		while(q.size())
		{
			now=q.front();q.pop();
//			cout<<now<<" "<<_dis[now]<<endl;
			for(int i=1;i<=n;++i)
			{
				if(_b[now][i]==0)continue;	
				for(int j=1;j<=k[i];++j)
				{
//						cout<<_a[i][j-1]<<" "<<_dis[now]+1<<endl;
					if(_dis[_a[i][j-1]]==1e18)
					{
						_dis[_a[i][j-1]]=_dis[now]+1;
//						cout<<_a[i][j-1]<<" "<<_dis[now]+1<<endl;
						if(_a[i][j-1]==v)
						{
							break;
						}
						q.push(_a[i][j-1]);
					}
				}
			}
		}
//		cout<<_dis[v]<<endl;
		cout<<_dis[v]*2*T+w[u]+w[v]<<"\n";
	}
}
void solve4()
{
	bool _b[500010][3];
	ll tmp=1e18,s[500010][3];
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)_b[j][i]=0;
		for(int j=1;j<=k[i];++j)
		{
			_b[_a[i][j-1]][i]=1;
			s[_a[i][j-1]][i]=_t[i][j-1];
		}
	}
	for(int i=1;i<=m;++i)
	{
		if(_b[i][1]&&_b[i][2])
		{
			tmp=min(tmp,s[i][1]+s[i][2]);
		}
	}
	while(q--)
	{
		cin>>u>>v;
		if(_b[u][1]&&_b[v][1])
		{
			if(_b[u][2]&&_b[v][2])
			{
				cout<<w[u]+w[v]+min(s[u][1]+s[v][1],s[u][2]+s[v][2])<<"\n";
			}
			else
			{
				cout<<w[u]+w[v]+s[u][1]+s[v][1]<<"\n";
			}
		}else
		{
			if(_b[u][2]&&_b[v][2])
			{
				cout<<w[u]+w[v]+s[u][2]+s[v][2]<<"\n";
			}
			else
			{
				if(_b[u][1]&&_b[v][2])
				{
					cout<<w[u]+w[v]+tmp+s[u][1]+s[v][2]<<"\n";
				}
				else 
				{
					cout<<w[u]+w[v]+tmp+s[u][2]+s[v][1]<<"\n";
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
	{
		cin>>w[i];
	}	
	if(m<=500)
	{
		solve1();
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];++j)
		{
			cin>>u>>v;
			_a[i].pb(u);
			_t[i].pb(v);
			if(i==1&&j==1)
			{
				T=v;
			}
			else if(T!=v)
			{
				flag2=0;
			}
		}
		if(k[i]>2)
		{
			flag1=0;
		}
	}	
	if(flag1)
	{
		solve2();
		return 0;
	}
	if(flag2)
	{
		solve3();
		return 0;
	}
	if(n<=2)
	{
		solve4();
		return 0;
	}
	return 0;
}
