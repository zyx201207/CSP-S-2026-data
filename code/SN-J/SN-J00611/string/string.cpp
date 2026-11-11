#include <bits/stdc++.h>
#define int long long
#define S "string"
#define FI freopen(S".in","r",stdin);
#define FO freopen(S".out","w",stdout);
using namespace std;

const int N = 2e5+10;
int n,ans;
deque<pair<char,int>> q;
signed main()
{
	FI;FO;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		int x;
		char ss;
		cin >> x >> ss;
		q.push_back({ss,x});
	}
//	for (auto i : q) cout << i.first << " " << i.second << "\n";
	while (q.size()>1)
	{
		auto topp = q.front();
		auto endd = q.back();
		q.pop_front();
		q.pop_back();
		if (topp.first==endd.first) 
		{
			if (topp.second<endd.second) q.push_back({endd.first,endd.second-topp.second});
			else if (topp.second>endd.second) q.push_front({topp.first,topp.second-endd.second});
		}
		else
		{
			ans+=min(topp.second,endd.second);
			if (topp.second<endd.second) q.push_back({endd.first,endd.second-topp.second});
			else if (topp.second>endd.second) q.push_front({topp.first,topp.second-endd.second});
		}
	}
	cout << ans;
	return 0;
}
/*
3
2 a
2 b
1 c
*/
