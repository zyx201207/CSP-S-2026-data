#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, ans, a[1000005];
char c[3000005];
string s = "", r_s = "";
void fast()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
}
signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	fast();
	cin>>n;
	for (int i = 1;i <= n;i++)
		cin>>a[i]>>c[i];
	for (int i = 1;i <= n;i++)
	{
		int t = a[i];
		while (t--)
			s += c[i];
	}
	r_s = s;
	reverse(r_s.begin(), r_s.end());
	if (s == r_s)
	{
		cout<<"0";
		return 0;
	}
	for (int i = 1;i <= s.size() / 2;i++)
	{
		if (s[i] != r_s[i])
			ans++;
	}
	cout<<ans + 1;
	return 0;
}
/*
there are some TLE:(
maybe 50pts?
*/
