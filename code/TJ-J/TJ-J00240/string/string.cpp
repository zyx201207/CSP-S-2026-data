#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
string s;
ll ans;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	ll pos1 = 1;
	for(int i = 1; i <= n; i++)
	{
		ll a;
		char b;
		cin >> a >> b;
		while(a--)
		{
			s[pos1] = b;
//			cout << s[pos1];
			pos1++;
//			cout << pos1 << " ";
		}
	}
	ll pos2 = pos1 - 1;
	for(int i = 1; i * 2 <= pos1; i++)
	{
		if(s[i] != s[pos2])
		{
			ans++;
//			cout << i << " " << pos2 << endl;
			char c = s[i];
			s[pos2] = c;
		}
		pos2--;
	}
	cout << ans;
	return 0;
}
