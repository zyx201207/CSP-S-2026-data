#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n;
long long a[N];
char c[N];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	long long r = n + 1, p = a[1], q = 0, ans = 0, b = 0;
	for(int l = 1; l <= n, l < r; l++){
		if(b > 0){
			 if(c[l] != c[r]){
				if(p >= q) ans += b;
				else ans = ans + a[l];
			}
		}
		while(r > 1 && l < r - 1 && p > q){
			r--;
			q = q + a[r];
			if(c[l] != c[r]){
				if(p >= q) ans += a[r];
				else ans = ans + a[r] - (q - p);
			}
		}
		b = q - p;
		p = p + a[l + 1];
		
	}
	cout << ans;
	return 0;
}
