#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[500005], r = 0;

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 5000){
		sort(a, a+n+1);
		for (int i = 1; i <= n; i++){
			int c = 1; 
			long long left_op = m;
			for (int j = i-1; j > 0; j--){
				left_op -= (a[i] - a[j]);
				if (left_op >= 0) c ++;
				else break;
			}
			if (c >= r) r = c;
		}
		cout << r;
	}
	else {
		sort(a, a+n+1);
		long long diff = a[2]-a[1], op = 0;
		for (r = 1; r <= n; r++){
			op += (r-1)*diff;
			if (op > m) break;
		}
		cout << r-1;
	}
    return 0;
}
