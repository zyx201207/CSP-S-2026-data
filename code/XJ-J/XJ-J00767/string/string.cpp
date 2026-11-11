#include<bits/stdc++.h>
using namespace std;
long long int n, m, sum, k, d;
string s;
char c;
int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> m >> c;
		d = m;
		while (d --) {
			s[++ k] = c;
		}
	} 
	for (int i = 1; i <= n; i ++) {
		for (int j = n; j >= 1; j --) {
			if (s[i] != s[j]) {
				sum ++;
			}
		}
	}
	cout << sum / 2;
	return 0;
}
