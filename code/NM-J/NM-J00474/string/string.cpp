#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
string s;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
	cin >> n;
	for (ll i = 1; i <= n; i++)
	{
		ll a;
		cin >> a;
		char c;
		cin >> c;
		for (ll i = 1; i<= a; i++)
		{
			s += c;
		}
	}
	//cout <<s;
	string s1 = s;
	//cout << endl;
	reverse(s1.begin(), s1.end());
	//cout << s1;
	ll cnt = 0;
	for (ll i= 0; i< n; i++)
	{
		if (s[i] != s1[i])cnt++;
	}
	cout << cnt;
    return 0;
}

