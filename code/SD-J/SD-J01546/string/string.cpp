#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long a[N];
char c[N];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	long long n;
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i] >> c[i];
	string s = " ";
	long long L = 0;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= a[i];j++) s += c[i];
		L += a[i];
	}
	int ans = 0;
	for(int i = 1;i <= L / 2;i++)
	{
		if(s[i] != s[L - i + 1]) ans++;
	}
	cout << ans << '\n';
	return 0;
}
