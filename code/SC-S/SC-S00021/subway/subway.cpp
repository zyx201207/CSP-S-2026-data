#include<bits/stdc++.h>
using namespace std;
const int MAX=1.5e6;
//将每一条线路缩为1点
//将每个站台、站厅、地铁口视为1点
//直接在两个线路之间连边
//求最短路
#define ull unsigned long long
#define ud unsigned
#define sub
ud c,n,m,d,q;
struct edge
{
	ull v;
	ud t;
};
const bool operator<(const edge a,const edge b)
{
	return a.t<b.t;
}
ull dt[510][510];
vector<edge>ll[MAX];
set<edge>tt[MAX];//线线 厅台
ud kt[MAX];//口厅
ud cnt;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifdef sub
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
#endif
	cin>>c>>n>>m>>d>>q;
	//口[1,m] 厅[m+1,2m] 台[2m+1,cnt]
	cnt=m;
	for(ud i=1;i<=m;i++)
	{//连接口厅
		ud w;
		cin>>w;
		kt[i]=w;
	}
	for(ud i=0;i<n;i++)
	{//连接厅台
		ud a,t,k;
		cin>>k;
		++cnt;
		for(ud f=0;f<k;f++)
			cin>>a>>t,
			tt[cnt].insert(edge{t,a}),
			tt[a].insert(edge{t,cnt});
	}
	for(ud i=1;i<=m;i++)
	{
		for(auto f:tt[i])
			for(auto j:tt[i])
				if(f.t!=j.t)
					ll[f.t-m].emplace_back(edge{f.v+j.v,j.t-m});
	}
	memset(dt,0x3f,sizeof dt);
	for(ud i=1;i<=cnt-m;i++)
	{
	queue<ud>qe;
	qe.emplace(i);
	dt[i][i]=0;
	while(!qe.empty())
	{
		ud v=qe.front();
		qe.pop();
		for(auto j:ll[v])
		{
			if(dt[i][j.t]>=dt[i][v]+j.v)
			{
				qe.emplace(j.t);
				dt[i][j.t]=dt[i][v]+j.v;
			}
		}
	}
	}
	for(ud i=0;i<q;i++)
	{
		ud x,y;
		cin>>x>>y;
		ull ans=1e18;
		for(auto f:tt[x])
			for(auto j:tt[y])
				ans=min(ans,dt[f.t-m][j.t-m]+f.v+j.v);
		cout<<ans+kt[x]+kt[y]<<'\n';
	}
}