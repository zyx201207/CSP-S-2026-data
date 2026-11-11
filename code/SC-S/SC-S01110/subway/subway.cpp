#include<bits/stdc++.h>
#define Fopen(FNAME) freopen(FNAME".in","r",stdin);freopen(FNAME".out","w",stdout);
using namespace std;
using ll=long long;
using PII=pair<int,int>;
using PLI=pair<ll,int>;
using PLL=pair<ll,ll>;
using ve=vector<int>;
const int N=5e2+9,mod=1e9+7,M=5e5+9;

int case_num,n,m,d,query_num,p,k,T=1;
int w[M];
vector<PII> r[M+N];
vector<PII> subway_infm[N];
//地铁编号 1~n 换乘站编号从n+1开始映射to_new
int subway_cnt[M],to_new[M];
vector<PII> mp[M+N];//地图点->乘坐地铁，时间
ll dis[N][N];//dis[i][j] 从i号线路到j号线路所需最短时间
ll disex[M];
bool vis[N];
void solve(int tcase)
{
	cin>>case_num>>n>>m>>d>>query_num;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k_num;cin>>k_num;
		for(int j=1;j<=k_num;j++)
		{
			int a,t;
			cin>>a>>t;
			subway_infm[i].push_back({a,t});
			subway_cnt[a]++;
		}
	}
	int cnt_new=n;
	for(int i=1;i<=m;i++)
	{
		if(subway_cnt[i]>1)//可换乘
		{
			to_new[i]=++cnt_new;
		}
	}
	for(int u=1;u<=n;u++)
	{
		for(PII x:subway_infm[u])
		{
			int v=x.first,now_w=x.second;
			mp[v].push_back({u,now_w});
			if(subway_cnt[v]>1)
			{
				v=to_new[v];
				r[u].push_back({v,now_w});
				r[v].push_back({u,now_w});
			}
		}
	}
//	n=cnt_new;
	priority_queue<PLI> q;
	for(int i=1;i<=n;i++)
	{//雷霆dijisitela
		for(int j=1;j<=cnt_new;j++)vis[j]=0;
		for(int j=1;j<=n;j++)dis[i][j]=1e18;
		for(int j=n+1;j<=cnt_new;j++)disex[j]=1e18;
		dis[i][i]=0;
		q.push({dis[i][i],i});
		while(!q.empty())
		{
			int now=q.top().second;
			q.pop();
			ll dis_now;
			if(vis[now])continue;
			vis[now]=1;
			
			if(now>n)dis_now=disex[now];
			else dis_now=dis[i][now];
			for(PII x:r[now])
			{
				int to=x.first;ll to_w=x.second;
				if(to>n)
				{
					if(disex[to]>dis_now+to_w)
					{
						disex[to]=dis_now+to_w;
						q.push({-disex[to],to});
					}
				}
				else
				{
					if(dis[i][to]>dis_now+to_w)
					{
						dis[i][to]=dis_now+to_w;
						q.push({-dis[i][to],to});
					}
				}
			}
		}
	}
	for(int i=1;i<=query_num;i++)
	{
		int start_station,end_station;
		cin>>start_station>>end_station;
		ll ans=1e18;
//		cout<<"\n\n"<<w[start_station]+w[end_station]<<"\n\n";
		for(PII start_way:mp[start_station])
		{
			for(PII end_way:mp[end_station])
			{
				ll w_sum=start_way.second+end_way.second;
				int start_subway=start_way.first,end_subway=end_way.first;
				
//				cout<<start_subway<<' '<<end_subway<<'\n';
//				cout<<w_sum<<' '<<dis[start_subway][end_subway]<<'\n';
				
				ans=min(ans,w_sum+dis[start_subway][end_subway]);
			}
		}
		ans+=w[start_station]+w[end_station];
		cout<<ans<<'\n';
	}
}
int main(	)
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	Fopen("subway");
//	cin>>T;
	for(int i=1;i<=T;i++)
	{
		solve(i);
	}
	return 0;
}
/*
似乎每个站不太重要...

将图抽象为点集={地铁的点,换乘的站}边集={地铁换乘到站台}
				n+(0,m)					5e5
每次询问跑最短路 或是离线跑？好像有搞头
最多跑n次我说dj

15:50 B 差不多吧 还写了对拍
15:58 CD没搞头 推B...
17:00 药丸辣
17:19 写完了?
17:31 不会有艾斯贼看错样例了吧
wkwk样例全过
今天我 寒夜里看雪飘过
怀着冷却了的心窝飘远方
风雨里追赶 雾里分不清影踪
...

*/