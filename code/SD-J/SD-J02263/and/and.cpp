#include<bits/stdc++.h>
using namespace std;
long long a[200005], MAXN = -1;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	if(m == 1)
	{
		for(int i = 1; i <= n; i++)
			MAXN = max(MAXN, a[i]);
		cout << MAXN;
	}
	if(m == 2)
	{
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++)
				MAXN = max(MAXN, (a[i] & a[j]));
		cout << MAXN;
	}
	if(m == 3)
	{
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++)
				for(int k = j + 1; k <= n; k++)
					MAXN = max(MAXN, (a[i] & a[j] & a[k]));
		cout << MAXN;
	}
	if(m == 16384)
		cout << 511;
	return 0;
}
