#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int w[250005];
struct po
{
	int k,a[250005],t[500005];	
};
po p[500005];
int c,n,m,d,q,y,mi=1e9;
int dfs(int x,int time)
{
	int sum=0;
	if(x==y)
	{
		if(time!=0)
		{
			return time;
		}
		else
		{
			mi=min(mi,sum);
			sum=0;
			return mi;
		}
	}
	for(int j=1;j<=n;j++)
	{
		for(int l=1;l<=p[j].k;l++)
		{
			if(p[l].a[x])
			{
				sum+=dfs(l,p[j].t[l]);
			}
		}
	}
	sum=0;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].k;
		for(int j=1;j<=p[i].k;j++)
		{
			int z;
			cin>>z>>p[i].t[j];
			p[i].a[z]=1;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x;
		cin>>x>>y;
		mi=1e9;
		cout<<dfs(x,0)+w[x]+w[y]<<endl;
	}
	return 0;
} 
