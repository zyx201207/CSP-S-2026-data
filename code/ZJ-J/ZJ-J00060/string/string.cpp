#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) { return (b == 0)?(a):(gcd(b, a % b)); }
vector<pair<long long, char>> str;
int cnt = 0;
long long len = 0;

#define DEBUG 0

#if DEBUG
#define dbg(x) cerr << #x << ":" << x << '\n'
#else
#define dbg(x)
#endif

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, z;
	char x;
	cin >> n;
	cin >> z >> x;
	str.push_back({z, x});
	len += z;
	for (int i = 1; i < n; ++i)
	{
		cin >> z >> x;
		if (str[cnt].second == x)
			str[cnt].first += z;
		else
		{
			str.push_back({z, x});
			cnt++;
		}
		len += z;
	}
	long long GCD = str[0].first;
	for (auto p:str)
		GCD = gcd(GCD, p.first);
	for (auto p:str)
		p.first /= GCD;
	len /= GCD;
	if (cnt == 0)
	{
		cout << 0;
		return 0;
	}
	vector<pair<long long, char>> str_rev(str.rbegin(), str.rend());
	long long l = 0, r = len - 1;
	long long tmp1, tmp2;
	long long cntt = 0;
	char lc, rc;
	while (l <= r)
	{
		tmp1 = 0, tmp2 = 0;
		for (auto p:str)
		{
			tmp1 += p.first;
			if (tmp1 >= l)
			{
				lc = p.second;
				break;
			}
		}
		for (auto p:str_rev)
		{
			tmp2 += p.first;
			if (tmp2 >= len - r)
			{
				rc = p.second;
				break;
			}		
		}
		dbg(lc);
		dbg(rc);
		if (lc != rc)
			cntt++;
		l++, r--;
	}
	cout << cntt * GCD;
	return 0;
}
