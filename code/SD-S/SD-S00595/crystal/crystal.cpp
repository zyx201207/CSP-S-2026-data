#include <bits/stdc++.h>
using namespace std; 
long long n, m, x;
long long sum1 = 0;
long long a[500500], b[500500], c[500500];
long long ans = 1, sum, jian;
bool tttt = false;
int main() {
 	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(long long i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
			
	}
	sort(a + 1, a + n + 1);
	for(int i = 3; i<= n; i++){
		if(a[i] - a[i - 1] == a[i - 1] - a[i - 2]){
				tttt = true;
			}else{
				tttt = false;
			}
	}
	if(tttt){
		long long l = 0;
		if(a[1] - a[2] < 0){
			l = a[2] - a[1];
		}else {
			l = a[1] - a[2];
		}
		if(l == 0){
			cout << n;
			return 0;
		}
		ans = m / l;
		cout << ans;
		return 0;
	}
	sum /= n;
	
	ans = 0;
	for(long long i = 1; i <= n; i++){
		b[i] = a[i] - a[i - 1];
		c[i] = b[i] + c[i - 1];
	}
	long long maxx = 0;
	for(long long i = n; i > 1; i--){
		for(long long j = 1; j < i; j++){
			long long q = c[i] - c[j];
			if(q > maxx && q <= m){
				
				maxx = q;
				ans = i - j + 1;
			} 
		}
	}
	cout << ans;
	return 0;
}
