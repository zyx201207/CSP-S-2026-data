#include<bits/stdc++.h>
using namespace std;
int a[200005],vis[30];
int n,m;
int dfs(int pos,int t,int val)
{
	if(pos==n+1)
	{
		if(t==m)
		{
			return val;
		}
		return -1;
	}
	int res=-1;
	res=max(res,dfs(pos+1,t,val));
	if(t<m)
	{
		res=max(res,dfs(pos+1,t+1,val&a[pos]));
	}
	return res;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int s=-1,mx=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s=(s&a[i]);
		mx=max(mx,a[i]);
	}
	if(m==n)
	{
		cout<<s;
		return 0;
	}
	if(m==1)
	{
		cout<<mx;
		return 0;
	}
	if(m==2)
	{
		int x=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				x=max(x,(a[i]&a[j]));
			}
		}
		cout<<x;
		return 0;
	}
	cout<<dfs(1,0,-1);
	return 0;
} 
