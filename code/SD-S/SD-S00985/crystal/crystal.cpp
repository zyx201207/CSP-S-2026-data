#include<bits/stdc++.h>

using namespace std;

long long a[600010];
long long q[600010];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for(long long i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(long long i = 1; i <= n; i++){
		q[i] = q[i - 1] + a[i];
	}
	long long r = 0;
	long long c = 0;
	for(long long l = 1; l <= n; l++){
		while(r < n && a[r + 1] * ((r + 1) - l + 1) - (q[r + 1] - q[l - 1]) <= m) r++;
		c = max(c, r - l + 1);
	}
	cout << c << endl;




	return 0;
}
