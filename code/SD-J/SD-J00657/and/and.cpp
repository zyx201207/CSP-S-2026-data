#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001],ans=-1;
void dfs(int i,int j,long long l)
{
	if(i==n+1||j==0)
	{
		if(j==0)
		{
			ans=max(ans,l);
		}
		
		return;
	}
	dfs(i+1,m-1,a[i]);
	dfs(i+1,j,l);
	dfs(i+1,j-1,l&a[i]);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,m,0);
	cout<<ans;
	return 0;
} 
