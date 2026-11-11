#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define FOR(w, a) for(i64 i = w; i <= a; i++)
#define I ios::sync_with_stdio(0);
#define AC cin.tie(0);
#define T2 cout.tie(0);
#define l first
#define r second
#define pb push_back
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	I AC T2
	i64 n;
	string s = " ";
	cin >> n;
	FOR(1, n)
	{
		i64 x;
		char ch;
		cin >> x >> ch;
		FOR(1, x) s.pb(ch);
	}
	i64 l = 1, r = s.size() - 1, cnt = 0;
	while(l <= r)
	{
		if(s[l] != s[r]) cnt++, s[l] = s[r];
		l++, r--;
	}
	cout << cnt;
	return 0;
} 
