#include <bits/stdc++.h>
using namespace std;
long long n, a[200001], l = 1, r;
long long sum = 0;
char c[200001];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	r = n;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i]; 
	}if (n == 1){
		cout << 0;
		return 0;
	}while (l < r){
		if (a[l] > a[r]){
			
			if (c[l] != c[r]){
				sum += (a[l] - a[r]);
			}a[l] -= a[r];
			r -= 1;
		}else if (a[l] < a[r]){
			
			if (c[l] != c[r]){
				sum += (a[r] - a[l]);
			}a[r] -= a[l];
			l += 1;
		}else {
			if (c[l] != c[r]){
				sum += a[l];
			}r -= 1;
			l += 1;
		}
	}cout << sum;
	return 0;
}
