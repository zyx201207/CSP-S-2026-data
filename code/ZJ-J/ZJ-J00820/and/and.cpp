#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int a[40];
	int len=0;
	long long x;
}q[200005];
long long ans=-1e9;
long long summ[40];
void init(int i)
{
	long long xx=q[i].x;
	while(xx>0)
	{
		q[i].a[++q[i].len]=xx%2;
		summ[q[i].len]+=q[i].a[q[i].len];
		xx/=2;
	}
}
bool cmp1(node c,node d){
	return c.x>d.x;
}
bool cmp2(node c,node d)
{
	if(c.len!=d.len)return c.len>d.len;
	for(int i=c.len;i>=1;i--)
	{
		if(summ[i]<m)continue;
		return c.a[i]>d.a[i];
	}
		
}
void dfs(int u,long long sum,int last)
{
	if(u>=m)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=last+1;i<=n;i++)
	{
		dfs(u+1,sum&q[i].x,i);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long maxx=-1e9,ssum;
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>q[i].x;
		if(q[i].x!=i-1)flag=0;
		maxx=max(maxx,q[i].x);
		if(i==1)ssum=q[i].x;
		else ssum=ssum&q[i].x;
		init(i);
	}
	if(m==1)
	{
		cout<<maxx;
		return 0;
	}
	else if(m==n)
	{
		cout<<ssum;
		return 0;
	}
	else if(flag)
	{
		sort(q+1,q+n+1,cmp1);
		long long sum=q[1].x;
		for(int i=2;i<=m;i++)sum=sum&q[i].x;
		cout<<sum;
		return 0;
	}
	if(n>2000)
	{
		sort(q+1,q+n+1,cmp2);
		long long sum=q[1].x;
		for(int i=2;i<=m;i++)sum=sum&q[i].x;
		cout<<sum;
	}
	else
	{
		for(int i=1;i<=n;i++)dfs(1,q[i].x,i);
		cout<<ans;
	}
	return 0;
}
