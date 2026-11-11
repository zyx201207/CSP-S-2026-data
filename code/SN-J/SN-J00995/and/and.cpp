#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[20005],c[20005]; // 表示选不选第step个数 
stack<int> s;
void dfs(int step)
{
	if (step>n)
	{
		int cnt=0,cnt1=0;
		for (int i = 1;i<=n;i++)
		{
			if (c[i]==1) cnt1++;
		}
		int ans;
		if (cnt1==m)
		{
			for (int i = 1;i<=n;i++)
			{
				if (c[i]==1)
				{
					cnt++;
					if (cnt==1) ans = a[i];
					else ans = (ans&a[i]);
				}
			}	
		}
		s.push(ans);
		return;
	}
	for (int i = 0 ;i<=1;i++) // 0 no 1 yes
	{
		c[step]=i;
		dfs(step+1);
		
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	dfs(1);
	int maxn = 0;
	for (int i = 1;i<=s.size();i++)
	{
		maxn = max(maxn,s.top());
		s.pop();
	}
	cout << maxn;
	return 0;
}
