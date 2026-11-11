#include<bits/stdc++.h>
using namespace std;
const int slen=2e5+10;
long long a[slen];
int n,m;
int dfs(int node,int deep,int ans)
{
	if(deep==m)
	{
		return ans;
	}
	int g=-1;
	for(int i=node+1;i<n;i++)
	{
		g=max(g,dfs(i,deep+1,int(ans&a[i])));
	}
	return g;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int temp=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(i==0)	temp=a[i];
		else	temp=temp&a[i];
	}
	if(m==n)	
	{
		cout<<temp;return 0;
	}
	int ans=-1;
	for(int i=0;i<n;i++)
	{
		ans=max(ans,dfs(i,1,a[i]));
	}
	cout<<ans;
	return 0;
}