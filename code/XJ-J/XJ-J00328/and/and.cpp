#include<bits/stdc++.h>
using namespace std;
#include<math.h>
int n, m;
long long ans = 0;
long long a[100005];

void dfs(long long id, long long sum)
{
	if(id == m + 1)
	{
		ans = max(ans, sum);
		return;
	}
	for(int i = 1; i <= n; i ++)
	{
		sum = sum & a[i];
		dfs(id + 1, sum);
	}
}
int main()
{
	freopen("and.in ","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i ++)
	{
		cin>>a[i];
	}
	dfs(1, a[1]);
	cout<<ans;
	return 0;
 } 
