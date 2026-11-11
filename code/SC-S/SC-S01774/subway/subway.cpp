#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int to,w;
};
struct nnd{
	int v,w;
	operator<(const nnd &a)const{
		return a.w>w;
	}
};
int c,n,m,d,q,st,sd,k,id,ww,ans,sum;
int w[5*N];
node a[5*N][550];
int cnt[5*N],dis[550];
vector<node>x[550];
bool vis[550];

void dij(int s)
{
	priority_queue<nnd>q;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	q.push({s,0});
	vis[s]=1;
	while(!q.empty())
	{
		nnd xx=q.top();
		int u=xx.v;
		q.pop();
		if(vis[u])
			continue;
		vis[u]=1;
		for(auto dao:x[u])
		{
			if(dis[dao.to]>dis[u]+dao.w)
			{
				dis[dao.to]=dis[u]+dao.w;
				q.push({dao.to,dis[dao.to]});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);//记得改txt为in
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <=m ;++i)
	{
		cin>>w[i];
	}
	for(int i = 1;i <= n;++i)
	{
		cin>>k;
		for(int j = 1;j <= 2*k;++j)
		{
			cin>>id>>ww;
			a[id][++cnt[id]].to=i,a[id][cnt[id]].w=ww;//第i号线 第id个站台的权值
		} //第id个站台 共有cnt[id]个数据
		  //.to 代表在几号线中有此站 .w代表该线中权值
	}
	for(int i = 1;i <= m;++i)
	{
		if(cnt[i]<2)
			continue;
		for(int j = 1;j<=cnt[i];++j)
		{
			for(int k = j+1;k<=cnt[i];++k)
			{
				x[a[i][j].to].push_back({a[i][k].to,a[i][j].w+a[i][k].w});
				x[a[i][k].to].push_back({a[i][j].to,a[i][j].w+a[i][k].w});
			}  //
		}
	}
	while(q--)
	{
		cin>>st>>sd;//st起点 sd终点
		ans=1e9;
		sum=w[st]+w[sd];
		for(int i = 1;i <= cnt[st];++i)
		{
			dij(a[st][i].to);
			for(int j = 1;j <= cnt[sd];++j)
			{
				ans=min(ans,sum+dis[j]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}