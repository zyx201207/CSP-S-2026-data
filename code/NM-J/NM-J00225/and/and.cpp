#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0, m,a[100005], v[100005], maxn = 0;
void dfs (int step)
{
	if(step > n)
	{
		int sum = 255;
		int cnt1 = 0, cnt2 = 0;
		for (int i = 1; i <= n; i++)
		{
			if(v[i] == 1)
			{
				sum = sum & a[i];
				cnt2++;
			}
		}
		if(cnt2 == m)
		{
			maxn = max(maxn,sum);
		}
		return ;
	}
	for(int i = 0; i <= 1; i++)
	{
		v[step] = i;
		dfs(step + 1); 
	}
}
int main ()
{
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n; i++)
	{
		cin >> a[i];
	}
	dfs(1);
	cout << maxn;
	return 0;
}
