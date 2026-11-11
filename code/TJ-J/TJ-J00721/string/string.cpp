#include <bits/stdc++.h>
using namespace std;

#define int long long

list<pair<pair<int, int>, char> > l;

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, nowp = 1;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int a;
		char c;
		cin >> a >> c;
		l.emplace_back(make_pair(nowp, nowp + a - 1), c);
		nowp += a;
	}
	
	int sum = 0;
	
	while(l.size() > 1)
	{
		pair<pair<int, int>, char> le = l.front();
		l.pop_front();
		pair<pair<int, int>, char> ri = l.back();
		l.pop_back();
		int len = min(le.first.second - le.first.first + 1, ri.first.second - ri.first.first + 1);
		if(le.second == ri.second)
		{
			le.first.first += len;
			ri.first.second -= len;
			if(le.first.second - le.first.first + 1 > 0) l.emplace_front(le);
			if(ri.first.second - ri.first.first + 1 > 0) l.emplace_back(ri);
			continue;
		}
		le.first.first += len;
		ri.first.second -= len;
		if(le.first.second - le.first.first + 1 > 0) l.emplace_front(le);
		if(ri.first.second - ri.first.first + 1 > 0) l.emplace_back(ri);
		sum += len; 
	}
	cout << sum << '\n';
	
	return 0;
}
//rp++
