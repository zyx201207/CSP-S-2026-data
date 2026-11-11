#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,ans,maxn,a[200005];
bool vis[200005];
void dfs(int idx,int res)
{
	if(res <= ans)
	{
		return ;
	}
	if(idx > m)
	{
		ans = max(ans,res);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i] == 1)
		{
			continue;
		}
		vis[i] = 1;
		dfs(idx+1,res&a[i]);
		vis[i] = 0;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
 	cin >> n >> m;
 	for(int i=1;i<=n;i++)
 	{
 		cin >> a[i];
 		maxn = max(maxn,a[i]);
	}
	if(m == n)
	{
		ans = 2147483647;
		for(int i=1;i<=n;i++)
	 	{
	 		ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	else if(m == 1)
	{
		for(int i=1;i<=n;i++)
	 	{
	 		ans = max(ans,a[i]);
		}
		cout << ans;
		return 0;
	}
	else if(m == n-1)
	{
		for(int i=1,res=2147483647;i<=n;i++)
	 	{
	 		for(int j=1;j<=n;j++)
		 	{
		 		if(j != i)
		 		{
		 			res &= a[j];
				}
			}
			ans = max(ans,res);
		}
		cout << ans;
		return 0;
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	if(maxn < 4)
	{
		ans = 2147483647;
		for(int i=1;i<=m;i++)
		{
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	dfs(1,2147483647);
	cout << ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
