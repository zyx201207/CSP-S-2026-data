#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+100;
const int M=510;
int c,n,m,d,q;
long long w[N];
struct node
{
	int x,val,nxt;
}W[N];
int top;
int head[N];
void add(int x,int X,int val){return W[++top]={X,val,head[x]},head[x]=top,void();}
long long sum[M][M];
long long solve(int x,int y)
{
	long long res=1e18;
	for(int i=head[x];i;i=W[i].nxt)
	for(int j=head[y];j;j=W[j].nxt)
	res=min(res,sum[W[i].x][W[j].x]+W[i].val+W[j].val);
	return res;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		sum[i][j]=1e18;	
		for(int i=1;i<=n;i++)
		sum[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		long long k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			long long x,val;
			cin>>x>>val;
			for(int k=head[x];k;k=W[k].nxt)
			{
				int v=W[k].x;
				sum[v][i]=min(sum[v][i],W[k].val+val);
				sum[i][v]=min(sum[i][v],W[k].val+val);
			}
			add(x,i,val);
		}
	
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	for(int k=1;k<=n;k++)
	{
		sum[j][k]=min(sum[j][k],sum[j][i]+sum[i][k]);
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+solve(x,y)<<'\n';
	}
	return 0;
}
