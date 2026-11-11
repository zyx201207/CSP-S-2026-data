#include <bits/stdc++.h>
using namespace std;

long long n;
long long a[200010];
char b[200010];
int t[27];
int ans;
int maxn = -1;

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

	cin >> n;
	long long s = 0;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
		s += a[i];
		t[b[i] - 'a']++;
	}
	
	for (int i = 0; i <= 26; i++) {
		if (t[i] >= 1) {
			ans++;
		}
	}
	if (ans == 1) {
		cout << 0;
		return 0;
	}
	cout << s / 2;

    return 0;
}

