//这啥阅读理解
//所以坐地铁不用花时间对吧 
//从一个站厅到另一个需要t[x1][j]+t[x2][j]
 //考虑每条地铁
 //做linex之间的最短路
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int w[1000005],k[1000005];
//int a[500005][505],t[500005][505];//这个要改成vector 
vector<int> a[1005],t[1005];
 //int 6e7不会爆炸吧
long long dis[1000005];
int vis[1000005];
long long subway_to_subway[1005][1005];
vector<pair<int,int> > G[1000005];
vector<pair<int,int> > GG[1000005];

int id=2;
	int c,n,m,d,q;
void dij(int s)
{
	memset(dis,0x7f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<int> q;
	q.push(s);
	dis[s]=0;vis[s]=1;
	while(!q.empty())
	{
		int u=q.top();q.pop();
	//	if(vis[u])continue;
		
		for(auto _:G[u])
		{
			
			int v=_.first;
			int cost=_.second;
			if(vis[v])continue;
			if(dis[u]+cost<dis[v])
			{
				dis[v]=dis[u]+cost;
				q.push(v);vis[v]=1;
				
			}
		}
	}
	//for(int i=0;i<=m+10+n;i++)cout<<i<<' '<<dis[i]<<endl;
	
}

void dij_for_GG(int s)
{
	memset(dis,0x7f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<int> q;
	q.push(s);
	dis[s]=0;vis[s]=1;
	while(!q.empty())
	{
		int u=q.top();q.pop();
	//	if(vis[u])continue;
		
		for(auto _:GG[u])
		{
			
			int v=_.first;
			int cost=_.second;
			if(vis[v])continue;
			if(dis[u]+cost<dis[v])
			{
				dis[v]=dis[u]+cost;
				q.push(v);vis[v]=1;
				
			}
		}
	}
	//for(int i=0;i<=m+10+n;i++)cout<<i<<' '<<dis[i]<<endl;
	
}
signed main()
{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{//line i
	//we let line id = m+10+i;
	cin>>k[i];
	a[i].resize(k[i]+10);
	t[i].resize(k[i]+10);
	int lineid=m+10+i;
	
	for(int _=1;_<=k[i];_++)
	{
		//第 i条线路经过的第_个地铁站的id，
		//从_地铁站的站厅走到第i条线路的站台需要的时间
		cin>>a[i][_]>>t[i][_];
		//from_station_to_line[a[i][_]].push_back(t[i][_]);
		
		G[lineid].push_back({a[i][_],t[i][_]});
		G[a[i][_]].push_back({lineid,t[i][_]});
	}
	}
	
	//int tmp;cin>>tmp;dij(tmp);
	
	
	for(int i=1;i<=n;i++)
	{
		int lineid=m+10+i; 
		dij(lineid);
		/*
		for(int _=1;_<=m;_++)
		{
			if(vis[_]==1)
			{
			
				from_station_to_line[_][lineid-m-10]=dis[_];
			}
		}
		*/
		
		for(int _=m+10;_<=m+10+n;_++)
		{
			if(vis[_]==1)
			{
				subway_to_subway[lineid-m-10][_-m-10]=dis[_];
				subway_to_subway[_-m-10][lineid-m-10]=dis[_];
			}
		}
	} 
	/*
	cout<<"n*n:"<<n*n<<endl;
	int sztmp=0;for(int i=0;i<=m+10+n;i++)sztmp+=G[i].size();
	cout<<"size of G:"<<sztmp<<endl;
	sztmp=0;for(int i=0;i<=m+10+n;i++)sztmp+=GG[i].size();
	cout<<"size of GG:"<<sztmp<<endl;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)cout<<subway_to_subway[i][j]<<' ';cout<<endl;
	}
	*/
	
	
	/*
	
	注意到必然是起点->站厅->(一些subway_to_subway)->站厅->终点 
	//需要枚举。这部分是On2 
	//总复杂度O(n^2*q+nk) 
	//不是我去
	//一个O(nk)就基本没了呀
	//能做到O1查询？
	//目前所有的样例ex2 wa ex6,7 tle
	//ex2莫名其妙wa
	      起点->站厅->(一些subway_to_subway)->站厅->终点 
	//预处理     ^-----------------------^  这部分 
	
	//不对。瓶颈在Onk的dij
	//那这我没招了，跳了
	 //这ex5在我的电脑上跑了0.95s
	 //我不会要完蛋了吧 
	  //删掉define int long long就是0.45s
	  我删了吧，我感觉不会爆int 
	*/
	while(q--)
	{
		int xr,yr;cin>>xr>>yr;
		
		long long ans=LLONG_MAX;
		for(auto _:G[xr])
		{
			//upstream:	G[a[i][_]].push_back({lineid,t[i][_]});
			
			int to=_.first-m-10;
			int to_cost=_.second;
					
				for(auto _:G[yr])
				{
					//upstream:	G[a[i][_]].push_back({lineid,t[i][_]});
					
					int end=_.first-m-10;
					int end_cost=_.second;
					ans=min(ans,to_cost+subway_to_subway[to][end]+end_cost);
					//cout<<to<<"->"<<end<<endl;
					//cout<<to_cost<<' '<<subway_to_subway[to][end]<<' '<<end_cost;
					
					
				}
		
		}
		
		//cout<<ans<<' ';
		cout<<w[xr]+ans+w[yr]<<endl;
	}
	
	return 0;
	
 } 
