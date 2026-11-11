#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n,m,a[N],s[5],sum;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n ; i++) {
		cin >> a[i];
	}
	for(int i = m; i >= 1; i--) {
		s[1] = a[1] + i;
		for(int j = 1; j <= i; j++) {
			s[2] = a[2] + j;
			if(s[1] == s[2]) {
				for(int k = 3; k <= n ; k++) {
					if(s[1] == a[k]) {
						sum ++;
					}
				}
			}
		}
	}
	cout <<sum + 2;
	return 0;
}
