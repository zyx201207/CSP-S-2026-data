#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5+10;
int n;
ll a[N];
char c[N];
string s;
ll ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		char p;
		cin >> a[i] >> p;
		for (int j = 1;j <= a[i];j++)
		{
			s += p;
		}
		c[i] = p;
	}
	int len = s.size();
	for (int i = 0;i < len/2;i++)
	{
		int r = len-i-1;
		if (s[i] != s[r])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
