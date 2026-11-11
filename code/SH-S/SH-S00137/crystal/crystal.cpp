#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
int n;
long long a[N], m;
bool A = true, B = true;
bool cmp(long long a, long long b){
	return a < b;
}
int main (){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		if(a[i] != i + 1){
			A = false;
		}
		if(i >= 2){
			if(a[i] - a[i - 1] != a[i - 1] - a[i - 2]){
				B = false;
			}
		}
	}
	sort(a, a + n, cmp);
	if(A == true){
		long long tmp = sqrt(2 * m) - 2;
		while((tmp + 1) * (tmp + 2) <= (m * 2)){
			tmp += 1;
		}
		cout << tmp + 1 << "\n";
	}else if(B == true){
		long long x = a[1] - a[0];
		long long tmp = sqrt(2 * x * m) - 2;
		while((tmp + a[0] + 1) * (tmp + x + a[0] - 1) <= (m * 2 * x)){
			tmp += 1;
		}
		long long ans = (tmp - a[0]) / x + 1;
		cout << ans + 1 << "\n";
	}else{
		int ans = 0;
		for(int i = n - 1; i >= 0; i --){
			for(int j = 0; j < i; j ++){
				long long cnt = 0;
				for(int k = j; k <= i; k ++){
					cnt += a[i] - a[k]; 
				}
				if(cnt <= m){
					ans = max(ans, i - j + 1);
					break;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0; 
}
// rp++ 
