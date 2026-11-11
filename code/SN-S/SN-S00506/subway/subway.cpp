//西安含光中学 吕家名 SN-S00506 
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int k[510];
struct edge
{
	int nxt,to,w;
}e[2010];
int head[1010],cnt;
void add(int u,int v,int w)
{
	e[++cnt].nxt=head[u];
	e[cnt].to=v;
	e[cnt].w=w;
	head[u]=cnt;	
}
struct node
{
	int id;
	long long dis;
	bool operator <(const node &b) const
	{
		return dis>b.dis;
	}
};
bool vis[500010];
long long w[500010];
struct huan
{
	int id;//换乘到谁 
	int t;//这段耗时 
};
vector<huan> huant[500010]; 
vector<int> v[500010];
long long disp[510][510];//johnson！！！哭
void dijp(int s)
{
	priority_queue<node> q;
	for(int i=1;i<=n;i++)
	{
		disp[s][i]=0x3f3f3f3f3f3f3f3f;
		vis[i]=0;
	}
	disp[s][s]=0;
	q.push({s,0});
	while(!q.empty())
	{
		int u=q.top().id;
		int diss=q.top().dis;
		q.pop();
		if(vis[u])
			continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].to;
			if(disp[s][v]>disp[s][u]+e[i].w)
			{
				disp[s][v]=disp[s][u]+e[i].w;
				if(!vis[v])
				{
					q.push({v,disp[s][v]});
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
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	if(1)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>k[i];
			for(int j=1;j<=k[i];j++)
			{
				int a,b;//换乘到i 这段耗时b 
				cin>>a>>b;//经过此站点
				//对于每两个线路之间记录信息：换乘时间 
				huant[a].push_back({i,b});
				//a点从i换乘到站厅的时间 
				if(huant[a].size()>=1)//可以换乘 
				{
					for(auto tr : huant[a]) 
					{
						if(tr.id==i)
							continue;
						add(i,tr.id,tr.t+b);//建边
						add(tr.id,i,tr.t+b);
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			dijp(i);
		 } 
		// 我没背诵全源最短路 hl2还有人提醒过背 我背了一堆tarjan  
		for(int i=1;i<=q;i++)
		{
			int x,y;
			cin>>x>>y;
			long long ans=0x3f3f3f3f3f3f3f3f;
			for(auto tr1 : huant[x])
			{
				for(auto tr2 : huant[y])
				{
					//对于每个火车跑一遍最短路	
					ans=min(ans,min(disp[tr2.id][tr1.id]+tr1.t+tr2.t+w[x]+w[y],disp[tr1.id][tr2.id]+tr1.t+tr2.t+w[x]+w[y]));
				}
			} 
			cout<<ans<<"\n";
		} 
	 } 
	//cerr<<clock()<<endl;
}
