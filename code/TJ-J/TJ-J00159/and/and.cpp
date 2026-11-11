#include<iostream>
#include<cmath>
using namespace std;
long long n,m,maxn,a[200005],vis[200005];
void dfs(int step,int sum)
{
	if(step==m)
	{
		maxn=max(sum,maxn);
		return;
	}
	if(step==n)return;
	for(int i=step;i<=n;i++)
	{
		dfs(step+1,sum);
		dfs(step+1,sum&a[i]);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,11111111);
	cout<<maxn;
	return 0;
}
