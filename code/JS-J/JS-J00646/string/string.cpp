#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll cnt = 1, ans;
string s;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
		ll k;
		char c;
		cin >> k >> c;
		for(int i = cnt; i < cnt + k; i++)
		{
			s[i] = c;
		}
		cnt += k;
    }
    ll len = cnt - 1;
    ll mid = len / 2;
    for(int i = 1; i <= mid; i++)
    {
		if(s[i] != s[len + 1 - i]) ans++;
	}
	cout << ans;
    return 0;
}
