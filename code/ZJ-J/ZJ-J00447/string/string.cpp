#include <bits/stdc++.h>
using namespace std;
int num[200005];
char c[200005];;
long long s[200005], e[200005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	long long len = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> num[i] >> c[i];
		s[i] = len+1;
		len += num[i];
		e[i] = len;
	}
	long long l = 1, r = len;
	int le = 1, re = n;
	long long ans = 0;
	while (l < r)
	{
		char ll = c[le], rr = c[re];
		//cout << ll << " " << rr << "\n";
		if (e[le] - l + 1 <= r - s[re] + 1)
		{
			//cout << "Left\n";
			//cout << e[le] - l + 1 << " " << r - s[re] + 1 << "\n";
			//cout << l << " " << r << "\n";
			if (ll != rr)	{ans += e[le]- l + 1;}
			r -= (e[le]-l+1);
			l += (e[le]-l+1);
			le++;
		}
		else if (r - s[re] + 1 < e[le] - l + 1)
		{
		//	cout << "Right\n";
		//	cout << e[le] - l + 1 << " " << r - s[re] + 1 << "\n";
		//	cout << l << " " << r << "\n";
			if (ll != rr)	ans +=r- s[re]+1;
			l += (r-s[re]+1);
			r -= (r- s[re]+1);
			re--;
		}
	}
	cout << ans;
}