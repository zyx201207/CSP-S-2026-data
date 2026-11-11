#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200001];
int mx=0;
void dfs(int djg,int yq,int dq)
{
	if(djg==21)
	{
		if(yq==m)
		{
			if(dq>=mx)mx=dq;
		}
		return;
	}
	dfs(djg+1,yq+1,dq&a[djg]);
	dfs(djg+1,yq,dq);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=20)
	{
		dfs(1,0,INT_MAX);
		cout<<mx;
		return 0;
	}
	else if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	else if(m==n)
	{
		int j=INT_MAX;
		for(int i=1;i<=n;++i)
		{
			j=j&a[i];
		}
		cout<<j;
	}
	else if(m==2)
	{
		int mxx=0;
		for(int i=1;i<2000;++i)
		{
			for(int j=i+1;j<=2000;++j)
			{
				if(a[i]&a[j]>=mxx)mxx=a[i]&a[j];
			}
		}
		cout<<mxx;
	}
	else
	{
		int j=INT_MAX;
		for(int i=n;i>=n-m+1;--i)
		{
			j=j&a[i];
		}
		cout<<j;
	}
	return 0;
}