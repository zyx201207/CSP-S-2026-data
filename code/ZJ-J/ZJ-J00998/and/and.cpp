#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200100];
long long ans=-1;
void dfs(int u,long long cnt,int num)
{
	if(u==m)
	{
		ans=max(ans,cnt);
		return;
	}
	for(int i=num+1;i<=n;i++)
	{
		if(u==0)
		{
			u++;
			dfs(u,a[i],i);
			u--;
		}
		else
		{
			long long k=cnt&a[i];
			u++;
			dfs(u,k,i);
			u--;			
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
