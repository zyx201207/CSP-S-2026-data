#include <bits/stdc++.h>
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3f;
long long f[3005][3005],a[3005][3005],dist[3005],flag[10005],c,n,m,d,q;
struct node
{
	int x,dis;
	friend bool operator<(node a,node b)
	{
		return a.dis>b.dis;
	}
}e[100005];
void kruskal(int s,int pos)
{
	memset(flag,0,sizeof(flag));
	memset(dist,0x3f,sizeof(dist));
	queue<node>q;
	q.push({s,0});
	dist[s]=0;
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		if(flag[t.x]==1) continue;
		flag[t.x]=1;
		for(int i=1;i<=2*m+n;i++)
		{
			if(a[t.x][i]==0) continue;
			if(dist[i]>dist[t.x]+a[t.x][i])
			{
				dist[i]=dist[t.x]+a[t.x][i];
				q.push({i,dist[i]});
			}
		}
	}
	cout<<dist[pos]<<endl;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int i,j,k,t,t1,t2;
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)
	{
		cin>>t;
		a[i][i+m]=a[i+m][i]=t;
	}
	for(i=1;i<=n;i++)
	{
		cin>>k;
		for(j=1;j<=k;j++)
		{
			cin>>t1>>t2;
			a[t1+m][i+2*m]=a[i+2*m][t1+m]=t2;
		}
	}
//	for(i=1;i<=2*m+n;i++)
//	{
//		for(j=1;j<=2*m+n;j++)
//		{
//			if(i==j) f[i][j]=0;
//			else f[i][j]=inf;
//		}
//	}
//	for(k=1;k<=2*m+n;k++)
//	{
//		for(i=1;i<=2*m+n;i++)
//		{
//			for(j=1;j<=2*m+n;j++)
//			{
//				if(i!=k&&k!=j) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
//			}
//		}
//	}
	while(q--)
	{
		cin>>t1>>t2;
		kruskal(t1,t2);
		//cout<<f[t1][t2]<<endl;
	}
	return 0;
}
