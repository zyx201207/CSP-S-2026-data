#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node 
{
	int x,step;
};
vector<int>v[1000005];
bool cmp(node a,node b)
{
	return a.x<b.x;
}
int vis[5005][5005],dis[5005][5005],n,d,a[1000005];
int bfs(int s,int t)
{
	int cnt=0,la=0;
	queue<node>q;
	q.push({s,0});
	while(q.size())
	{
		auto u=q.front();
		q.pop();
		if(u.step>dis[s][t])
		{
			continue;
		}
		if(u.x>=t)
		{
			cnt++;
			if(cnt>=3)
			{
				return 0;
			}
			continue;
		}
		if(u.step!=la)
		{
			la=u.step;
			vector<node>p;
			p.push_back(u);
			while(q.size())
			{
				p.push_back(q.front());
				q.pop();
			}
			sort(p.begin(),p.end(),cmp);
			int len=p.size();
			for(int i=0;i<min(3ll,len);i++)
			{
				q.push(p.back());
				p.pop_back();
			}
			continue;
		}
		if(vis[u.x][t]!=0&&u.step+dis[u.x][t]==dis[s][t])
		{
			cnt+=vis[u.x][t];
			if(cnt>=3)
			{
				return 0;
			}
			continue;
		}
		for(auto i:v[u.x])
		{
			if(i>=t)
			{
				q.push({t,u.step+1});	
				break;
			}
			q.push({i,u.step+1});
		}
	}
	vis[s][t]=cnt;
	if(cnt==2)
	{
		return 1;
	}
	return 0;
}
void minn(int s,int t)
{
	queue<node>q;
	q.push({s,0});
	while(q.size())
	{
		auto u=q.front();
		q.pop();
		if(dis[u.x][t]<1e17)
		{
			dis[s][t]=dis[u.x][t]+u.step;
			return ;
		}
		if(u.x>=t)
		{
			dis[s][t]=u.step;
			return ;
		}
		int l=u.x,r=n+1;
	 	while(l+1<r)
	 	{
	 		int mid=l+r>>1;
	 		if(a[mid]<=a[u.x]+d)
	 		{
	 			l=mid;
			}
			else
			{
			 	r=mid;
			}
		}
		if(l==u.x)
		{
			continue;
		}
		if(t<l)
		{
			dis[s][t]=u.step+1;
			return ;
		}
		q.push({l,u.step+1});
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			v[i].clear();
			for(int j=1;j<=n;j++)	
			{
				vis[i][j]=0;
				dis[i][j]=1e18;
			}
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		} 
		for(int i=1;i<=n;i++)
		{
		 	int l=i,r=n+1;
		 	while(l+1<r)
		 	{
		 		int mid=l+r>>1;
		 		if(a[mid]<=a[i]+d)
		 		{
		 			l=mid;
				}
				else
				{
				 	r=mid;
				}
			}
			if(l>=i+1)
			{
			 	v[i].push_back(l);
			 	if(l>=i+2)
				{
				 	v[i].push_back(l-1);
				 	if(l>=i+3)
					{
					 	v[i].push_back(l-2);
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				minn(i,j);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(bfs(i,j))
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	 } 
	return 0;
 }//15:45 想到40pts做法 
//15:47 发现题目给我们减负，送测试点编号。
//17:02 40pts 拿下 
//17:52 意识到BC在启示bfs
//17:59 发现bfs还要套线段树，不写了。 
