#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200001],p[200001],maxx;
void dfs(int s,int st)
{
	if(s==m)
	{
		long long ans;
		p[s]=a[st];
		ans=p[1];
		for(int i=2;i<=m;i++)
		{
			ans&=p[i];
		}
		maxx=max(maxx,ans);
		return;
	}
	for(int i=st;i<=n;i++)
	{
		p[s]=a[i];
		dfs(s+1,i+1);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,1);
	cout<<maxx;
	return 0;
}