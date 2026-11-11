#include<bits/stdc++.h>    
using namespace std;
#define LL long long
const int N = 5e5 + 5;
int n, ans = 1; 
LL m, a[N];
void caseB() {
	int d = a[2] - a[1];
	for(int i = 1; i <= n; i++) {
		LL tmp = i * 1LL * (i + 1) * d / 2;
		if(tmp > m) {
			ans = i;
			break;
		}
	}
 	return;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d %lld", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	if(n <= 5000) {
		for(int i = 1; i <= n; i++) {
			LL tmp = 0;
			for(int j = i - 1; j >= 0; j--) {
				if(tmp + a[i] - a[j] <= m && j != 0) tmp += a[i] - a[j];
				else {
					ans = max(ans, i - j);
					break;
				}
			}
		}
	}else {
		caseB();
	}
	printf("%d", ans);
 	return 0;
}
