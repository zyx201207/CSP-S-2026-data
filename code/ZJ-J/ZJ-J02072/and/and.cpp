#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001];
long long v[200001],vl=0,maxn=0;
void bfs(int p)
{
	int start=p;
	for(;start<=n-m+vl+1;)
	{
		if(vl<m)
		{
			v[++vl]=a[start];
			bfs(start+1);
			start++;
		}
		else
		{
			long long ans=v[1];
			for(int i=2;i<=vl;i++)
			{
				ans=ans&v[i];
			}
			maxn=max(maxn,ans);
			vl--;
		}
	}
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int i,j;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(i=1;i<=n;i++)
		{
			maxn=max(a[i],maxn);
		}
		cout<<maxn;
	}
	else if(m==n)
	{
		maxn=a[1];
		for(i=2;i<=n;i++)
		{
			maxn=maxn&a[i];
		}
		cout<<maxn;
	}
	else if(m==2)
	{
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}
	else
	{
		bfs(1);
		cout<<maxn;
	}
	return 0;
}
