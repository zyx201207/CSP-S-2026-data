#include <bits/stdc++.h>
using namespace std;

struct str
{
	long long s;
	char w;
};
vector<str> v;
long long ans = 0;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x;
		char y;
		cin >> x >> y;
		if(i != 0 && v[i-1].w == y)
		{
			v[i-1].s += x;
		}
		else
		{
			v.push_back({x, y});
		}
	}
	int l = 0, r = v.size()-1;
	while(l < r)
	{
		int minn = min(v[l].s, v[r].s);
		if(v[l].w != v[r].w)
		{
			ans += minn;
		}
		v[l].s -= minn;
		v[r].s -= minn;
		if(v[l].s == 0)
		{
			l++;
		}
		if(v[r].s == 0)
		{
			r--;
		}
	}
	cout << ans;
	return 0;
}
