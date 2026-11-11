#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;
int dfs(int x,vector<int> b,int s)
{
	if(s==m)
	{
		return a[x];
	}
	int mx=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]) continue;
		b[i]=1;
		int j=dfs(i,b,s+1);
		mx=max(mx,a[x]&j);
		b[i]=0;
	}
	return mx;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<int> b(m+1,0);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<=m;j++)
		{
			if(b[j]<a[i])
			{
				b[j]=a[i];
				break;
			}
		}
	}
	if(n<3005)
	{
		int mx=0;
		for(int i=1;i<=n;i++)
		{
			vector<int> b(n+1,0);
			mx=max(dfs(i,b,0),mx);
			
		}
		cout<<mx;
	}
	else
	{
		cout<<b[m];
	}
	return 0;
}
