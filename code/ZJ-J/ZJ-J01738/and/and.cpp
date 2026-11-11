#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,maxv=0;
int a[200005];
bool u[200005];
void dfs(int d,int ans,int cnt)
{
	if(cnt>=m||d>n)
	{
		if(cnt==m)
		{
			maxv=max(ans,maxv);
		}
		return ;
	}
	dfs(d+1,ans&a[d],cnt+1);
	dfs(d+1,ans,cnt);
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int Z=1;
	for(int i=1;i<=30;i++)Z*=2;
	dfs(1,Z-1,0);
	cout<<maxv;
	return 0;
}
