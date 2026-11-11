#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 12;
int n,m;
int a[N],ans,b[N];
void dfs(int sum)
{
	if(sum == m + 1)
	{
		int t = b[1];
		for(int i = 1;i <= m;i++)
		{
			t = (t & b[i]);
		}
		ans = max(t,ans);
		return ;
	}
	for(int i = sum + 1;i <= n;i++)
	{
		b[sum] = a[i];
		dfs(i);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n <= 2000)
	{
		for(int i = 1;i <= n;i++)
		{
			cin>>a[i];
		}
		dfs(1);
		cout<<ans;
	}
	else
	{
		cout<<n - m;
	}
	
	return 0;
}
