#include <bits/stdc++.h>
using namespace std;

int a[55];
queue <int> q;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	while(!q.empty())
		q.pop();
	for(int i = 1;i <= n;i++)
	{
		int t;
		cin >> t;
		for(int j = 0;j <= 30;j++)
			a[j] += ((t & (1 << j)) != 0);
		q.push(t);
	}
	int ans = 0,k = 30;
	while(!q.empty())
	{
		for(;k >= 0;k--)
			if(a[k] >= m)
				break;
		if(k < 0)
			break;
		int l = 1 << k;
		ans += l;
		for(int i = 1;i <= n;i++)
		{
			int t = q.front();
			q.pop();
			if(t & l)
				q.push(t);
			else
				for(int j = 0;j <= 30;j++)
					a[j] -= ((t & (1 << j)) != 0);
		}
		k--;
	}
	cout << ans;
	return 0;
}
