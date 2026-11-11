#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans;
bool f[200010];
void dfs(int sum,int num)
{
	if(num>=m)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
			f[i]=1;
			dfs(sum&a[i],num+1);
			f[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		f[i]=1;
		dfs(a[i],1);
		f[i]=0;
	}
	cout<<ans;
	return 0;
}