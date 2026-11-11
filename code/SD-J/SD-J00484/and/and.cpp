#include<bits/stdc++.h>
using namespace std;
int n, m, a[200005], ans;
vector<int>u, v;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		u.push_back(a[i]);
	} 
	for(int i = 30; i >= 0; i--)
	{
		v.clear();
		for(int x : u)
		{
			if(x & (1 << i))v.push_back(x);
		}
		if(v.size() >= m)u = v, ans += (1 << i);
	}
	cout << ans;
	return 0;
}
