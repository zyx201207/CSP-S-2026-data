#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, a, cnt = 0;
char c;
string s;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a >> c;
		for(int j = 1; j <= a; j++)
			s += c;
	}
	if(s.size() == 1)
	{
		cout << 0;
		return 0;
	}
	for(long long i = 0, j = s.size() - 1; i < j; i++, j--)
	{
		if(s[i] != s[j])
		{
			//cout << i << ' ' << j << endl;
			//cout << s[i] << ' ' << s[j] << endl;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
