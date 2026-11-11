#include<bits/stdc++.h>
using namespace std;
int n,m,maxn=0,ans;
int a[200005];
void dfs(int x)
{
	if(x>m)
	{
		maxn=max(maxn,ans);
		return;
	}
	for(int i=x;i<=n;i++)
	{
		if(x==1)
		{
			ans+=a[i];
		}	
		else
		{
			ans&=a[i];
		}
		dfs(x+1);
	}
	return;
}	
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	dfs(1);
	cout << maxn;
	return 0;
}
