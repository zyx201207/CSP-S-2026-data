#include <bits/stdc++.h>
using namespace std;
int n,a[200005],m;
bool vis[200005];
vector<int> v;
long long ans = -1;
void dfs(int u,long long x,int cnt)
{
	if (u == n + 1)
	{
		ans = max(ans,x);
		return ;
	}
	if (cnt > m) return ;
	int num = cnt;
	for (int j = u + 1;j <= n;j++)
	{
		if (!vis[j])
		{
            vis[j] = 1;
            v.push_back(a[j]);
            num++;
	        dfs(j + 1,x & a[j],num);
	        vis[j] = 0;
    	    v.pop_back();
    	    num--;
    	}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	dfs(0,(1 << 29) - 1,0);
	cout << ans;
}
