#include<bits/stdc++.h>
using namespace std;
long long a[500010], b[500010], c[500010];
int main(){
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 2; i <= n; i++){
		b[i - 1] = a[i] - a[i - 1] + b[i - 2];
	}
	for(int i = n - 1; i >= 1; i--){
		c[i] = a[i + 1] - a[i] + c[i + 1];
	}
//	for(int i = 1; i <= n - 1; i++){
//		cout << b[i] << ' ';
//	} 
//	cout << '\n';
//	for(int i = 1; i <= n - 1; i++){
//		cout << c[i] << ' ';
//	}
//	return 0;
	long long smax = 0, m1 = m, len = -1e9;
	for(int i = 1; i <= n - 1; i++){
		if(b[i] <= m1 || b[i] == len){
			smax = i;
			m1 -= b[i];
			if(b[i] == len){
				m1 += len;
			}
		}
		len = b[i];
	}
	long long smax2 = 0, m2 = m, len1 = -1e9;
	for(int i = n - 1, j = 1; i >= 1; i--, j++){
		if(c[i] <= m2 || b[i] == len1){
			smax2 = j;
			m2 -= c[i];
			if(c[i] == len1){
				m2 += len1;
			}
		}
		len1 = c[i];
	}
	cout << max(smax, smax2) + 1;
	return 0;
}