#include<bits/stdc++.h>
using namespace std;
vector<int>a;
vector<bool>used;
int n,m,ans;
void dfs(int step,int now)
{
	if(step>m)
	{
		ans=max(ans,now);
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(used[i])continue;
		used[i]=true;
		dfs(step+1,now&a[i]);
		used[i]=false;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	a.resize(n);
	used.resize(n,false);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		used[i]=true;
		dfs(1,a[i]);
		used[i]=false;
	}
	cout<<ans;
	return 0;
}
