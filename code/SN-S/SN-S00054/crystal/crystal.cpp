#include <bits/stdc++.h>

using namespace std;

int n;
long long m;
long long a[500001];
long long s[500001];
long long sum = 0; 
int ans = 0;

int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	sort (a + 1, a + n + 1);
	long long x;
	if (n % 2 == 0)
	    x = a[n / 2];
	else
	    x = a[n / 2 + 1];
	for (int i = 1; i <= n; i++) 
		    s[i] = x - a[i];
	sort (s + 1, s + n + 1);
	for (int i = 1; i <= n; i++)
	    if (sum + s[i] <= m && s[i] >= 0) 
	        sum += s[i], ans++;
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
