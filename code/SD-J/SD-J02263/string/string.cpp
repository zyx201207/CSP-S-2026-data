#include<bits/stdc++.h>
using namespace std;
long long n, a[200005], ans, mid, tot, l, r, z = 1;
char b[200005], c[200005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
		r += a[i];
		for(long long j = 1; j <= a[i]; j++)
			c[z + j - 1] = b[i];
		z += a[i];
	}
	l = 1;
	while(l <= r)
	{
		if(c[l] != c[r])
			tot++;
		l++, r--;
	}
	cout << tot;
	return 0;
}
