#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000005],h=0,mn=0,nm=0,v[2000005];
void dfs(int x,int s)
{
	if(x==m)
	{
		nm=max(s,nm);
		return; 
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]==1)continue;
		if(x==0)
		{
			v[i]=1;
			dfs(1,a[i]);
			v[i]=0;
		}
		else
		{
			v[i]=1;
			dfs(x+1,a[i]&s);
			v[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mn=max(mn,a[i]);
		if(i==1)h=a[i];
		else h=h&a[i];
	}
	if(m==1)
	{
		cout<<mn;
		return 0;
	}
	if(m==n)
	{
		cout<<h;
		return 0;
	}
	dfs(0,0);
	cout<<nm;
	return 0;
} 
