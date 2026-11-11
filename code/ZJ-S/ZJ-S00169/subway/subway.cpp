#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int M=5e5+5;
int c,n,m,d,q;
struct node2{
	int id,val;
};
vector<node2>G[M];
struct node{
	int id,size;//统计各点经过的线路数量和点编号
}b[M];
int f[505][505],k[505],size[M];
bool cmp(node a,node b)
{
	return a.size>b.size;
}
int w[M];
void init()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=LLONG_MAX;
	sort(b+1,b+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(b[i].size==1)
			break;
		for(auto k1:G[b[i].id])//线路号
			for(auto k2:G[b[i].id])//线路号
			{
				if(k1.id==k2.id)
					continue;
				f[k1.id][k2.id]=min(f[k1.id][k2.id],k1.val+k2.val);//两条线路在i点的换乘时间
				f[k2.id][k1.id]=min(f[k2.id][k1.id],k1.val+k2.val);
			}
	}
	for(int i=1;i<=n;i++)
		f[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
		{
			if(f[i][k]==LLONG_MAX)
				continue;
			for(int j=1;j<=n;j++)
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
			
	for(auto o:b)
		size[o.id]=o.size;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
//	a[i][j] 第i条线路的第j站
//	t[i][j] i站厅到j线路站台的时间
//	c[i][j] a[i][j]站通过的线路数量
//  k[i]记录了i线路经过的地铁站数量
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=2*k[i];j+=2)
		{	
			int x;
			cin>>x;
			b[x].size++;//记录通过a[i][j]线路的数量
			b[x].id=x;
			int t;
			cin>>t;//a[i][j]台线路到i的时间
			G[x].push_back({i,t});
		}
	}
	init();
	while(q--)
	{
		int xl=0,ans=LLONG_MAX,st,ed;
		cin>>st>>ed;
		for(auto i:G[st])//d (20)
			for(auto j:G[ed])//d (20)
				ans=min(ans,f[i.id][j.id]+i.val+j.val);	
		cout<<ans+w[st]+w[ed]<<"\n";
	}
	return 0;
}
/*
转化为求st所在线路到ed所在线路所需最小时间
*/