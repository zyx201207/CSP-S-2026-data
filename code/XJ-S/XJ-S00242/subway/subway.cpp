#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
struct node{
	int id,ans;
	friend bool operator<(node x,node y)
	{
		return x.ans>y.ans;
	}
};
struct edge{
	int x,y,idx,u;
}f[M];
long long c,n,m,d,e,u[M],k[M],a[M],sum[M],vis[M];
vector<node>q[M];
priority_queue<node>s;
bool cmp(edge x,edge y)
{
	return x.x<y.x;
}
bool cmp1(edge x,edge y)
{
	return x.idx<y.idx;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>e;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i];
	}
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		for(int j=1;j<=t;j++)
		{
			cin>>a[j]>>k[j];
			for(int o=1;o<j;o++)
			{
				q[a[o]].push_back((node){a[j],k[j]+k[o]});
				q[a[j]].push_back((node){a[o],k[j]+k[o]});
			}
		}
	}
	for(int i=1;i<=e;i++)
	{
		cin>>f[i].x>>f[i].y;
		f[i].idx=i;
	}
	sort(f+1,f+1+e,cmp);
	for(int i=1;i<=e;)
	{
		memset(sum,0x3f,sizeof(sum));
		memset(vis,0,sizeof(vis));
		s.push((node){f[i].x,0});
		sum[f[i].x]=0;
		while(s.size())
		{
			node now=s.top();s.pop();
			if(vis[now.id]==1)continue;
			vis[now.id]=1;
			for(int j=0;j<q[now.id].size();j++)
			{
				node v=q[now.id][j];
				if(sum[v.id]>now.ans+v.ans)
				{
					sum[v.id]=now.ans+v.ans;
					s.push((node){v.id,sum[v.id]});
				}
			}
		}
		f[i].u=sum[f[i].y]+u[f[i].x]+u[f[i].y];
		i++;
		while(f[i].x==f[i-1].x&&i<=e)
		{
			f[i].u=sum[f[i].y]+u[f[i].x]+u[f[i].y];
			i++;
		}
	}
	sort(f+1,f+1+e,cmp1);
	for(int i=1;i<=e;i++)
	{
		cout<<f[i].u<<'\n';
	}
	return 0;
 } 
