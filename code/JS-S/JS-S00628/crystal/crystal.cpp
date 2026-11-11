#include <bits/stdc++.h>
using namespace std;

long long n, m, a[(int)5e5 + 7], s[(int)5e5 + 7];

int ans = 1;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		s[i] = s[i - 1] + a[i];
	}
	for(int i = 1; i <= n; i++){
		int l = 1, r = i;
		while(l < r){
			int mid = (l + r) >> 1;
			if((i - mid + 1) * a[i] - (s[i] - s[mid - 1]) > m){
				l = mid + 1;
			}else r = mid;
		}
		ans = max(ans, i - r + 1);
	}
	printf("%d\n", ans);
	return 0;
}
