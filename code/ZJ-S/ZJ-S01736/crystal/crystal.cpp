#include <bits/stdc++.h>
using namespace std;

int n, ans;
long long m, a[500005], s[500005];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++){
		s[i] = s[i - 1] + a[i];
	}
	/*
	for (int i = 1; i <= n; i++){
		printf("%d\n", a[i]);
	}
	return 0;
	*/
	for (int i = 1; i <= n; i++){		
		int l = i, r = n;
		while (l + 1 < r){
			int mid = (l + r) / 2;
			if (s[mid] - s[i - 1] + m < 1LL * a[mid] * (mid - i + 1)){
				r = mid;
			}
			else{
				l = mid;
			}
		}
		if (s[l] - s[i - 1] + m >= 1LL * a[l] * (l - i + 1)){
			//if (l - i + 1 >= ans){
			//	printf("l:%d r:%d ans:%d\n", i, l, l - i + 1);
			//}
			ans = max(ans, l - i + 1);
		}
		/*
		for (int j = i; j <= n; j++){
			if (s[j] - s[i - 1] + m > 1LL * a[j] * (j - i + 1)){
				ans = max(ans, j - i);
			}
		}
		*/
	}
	printf("%d", ans);
	return 0;
}
