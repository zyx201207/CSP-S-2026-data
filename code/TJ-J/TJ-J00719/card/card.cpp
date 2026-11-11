#include<bits/stdc++.h>
using namespace std;
const int N = 500000;
const int M = 300000;
int a[N+2];
int b[N+2];
int c[N+2];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			b[i] = a[i];
		}
		for(int j = i; j <= n; j++) {
			for(int k = i; k < j; k++) {
				if(a[k] == a[j]) {
					for(int l = k; l <= j-1; l++) {
						a[l] = 0;
					}
				}
			}
		}
		for(int j = 1; j <= m; j++) {
			for(int k = i; k <= n; k++) {
				if(a[k] == j) {
					c[j] = c[j]+1;             
				}
			}
		}
	}
	for(int i = 1; i <= m; i++) {
		cout << c[i] << ' ';
	}
	return 0;
}
