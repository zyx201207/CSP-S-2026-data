#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int N = 2e5 + 5;
long long n;
long long a[N];
char c[N];
long long sum = 0;
bool flag = false;
long long maxn = -1e9;
string s;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (long long i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		maxn = max(maxn, a[i]);
		if (c[i] != c[1])
		{
			flag = true;
		}
	}
	if (!flag)
	{
		cout << "0\n";
		return 0;
	}
	if (maxn <= 50)
	{
		/*1.拼接成为完整*/
		long long ans = 0;
		for (long long i = 1; i <= n; i++)
		{
			for (long long j = 1; j <= a[i]; j++)
			{
				s += c[i];
			}
		}
		long long lens = s.size();
		for (long long i = 1, j = lens; i <= j; j--, i++)
		{
//			cout<<s[i-1]<<','<<s[j-1]<<'\n';
			if (s[i-1] != s[j-1])
			{
				ans++;
			}
		}
		cout << ans << '\n';
		return 0;
	}
	for (long long i = 1, j = n; i <= j; j--, i++)
	{
		if (c[i] != c[j])
		{
			sum += min(a[i], a[j]);
		}
		if (a[i] != a[j])
		{
			sum += max(a[i], a[j]) - min(a[i], a[j]);
		}
	}
	cout << sum << '\n';
	return 0;
}
