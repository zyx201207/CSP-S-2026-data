#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 500005;
const int maxm = 300005;
int n, m, a[maxn], f[maxn], s[maxn], sum[maxm], k = 1;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i) {
		memset( f, 0, sizeof(f) );
		memset( s, 0, sizeof(s) );
		k = 0;
		for(int j = i; j <= n; ++j) {
			if(f[ a[j] ] == 0) {
				k++;
				f[ a[j] ] = k;
				s[k] = a[j];
			} else {
				int _k = k;
				k = f[ a[j] ];
				for(int l = k+1; l <= _k; ++l) {
					f[ s[l] ] = 0;
					s[l] = 0;
				}
			}
		}
		/******************************************
		cout << k << ' ';
		for(int j = 1; j <= k; ++j) {
			cout << s[j] << ' ';
		}
		cout << '\n';
		******************************************/
		for(int j = 1; j <= k; ++j) {
			sum[ s[j] ]++;
		}
	}
	for(int i = 1; i <= m; ++i) {
		cout << sum[i] << ' ';
	}
	return 0;
}
