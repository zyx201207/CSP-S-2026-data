#include <bits/stdc++.h>
using namespace std;

int c, t, n;

long long d, x[(int)2e6 + 7], ans;

int l[(int)2e6 + 7], r[(int)2e6 + 7];

int anssl[(int)2e6 + 7], anssr[(int)2e6 + 7];
int anstl[(int)2e6 + 7], anstr[(int)2e6 + 7], is_ok[(int)2e6 + 7];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--){
		ans = 0;
		scanf("%d%lld", &n, &d);
		for(int i = 1; i <= n; i++){
			scanf("%lld", &x[i]);
		}
		for(int i = 1; i <= n; i++){
			int L = 1, R = i;
			while(L < R){
				int mid = (L + R) >> 1;
				if(x[mid] < x[i] - d) L = mid + 1;
				else R = mid;
			}
			l[i] = R;
			L = i, R = n;
			while(L < R){
				int mid = (L + R + 1) >> 1;
				if(x[mid] > x[i] + d) R = mid - 1;
				else L = mid;
			}
			r[i] = L;
		}
		for(int i = 1; i < n; i++){
			anssl[i] = max(max(l[i], l[i + 1]), anssl[i - 1]);
			anstr[i] = min(r[i], r[i + 1]);
			anssr[i] = i - 1, anstl[i] = i + 2;
			if(anssl[i] <= anssr[i - 1] && anstl[i] <= anstr[i - 1]){
//				if(anssr[i] <= anssr[i - 1]){
//	                              	is_ok[i] = -1;
//                                	continue;
//                      	}
//				if(anstl[i] >= anstl[i - 1] && anstr[i] <= anstr[i - 1]){
//					is_ok[i] = -1;
//					continue;
//				}
				int anssli = anssr[i - 1] + 1;
				anssr[i - 1] = anssl[i] - 1;
				anssl[i] = anssli;
				int anstli = anstr[i - 1] + 1;
				anstr[i - 1] = anstl[i] - 1;
				anstl[i] = anstli;
			}
		}
		for(int i = 1; i < n; i++){
			if(is_ok[i] == -1) continue;
			ans += /*(i - 1 - max(l[i], l[i + 1])) * max(0, anstr[i] - anstl[i] + 1) + max(0, anssr[i] - anssl[i] + 1) * (max(r[i], r[i + 1]) - i - 2) -*/ max(0, anssr[i] - anssl[i] + 1) * max(0, anstr[i] - anstl[i] + 1);
//			cout << anstr[i] << "\n";
			for(int j = anssl[i]; j <= anssr[i]; j++){
				if(r[j] >= anstl[i]){
					ans -= r[j] - anstl[i] + 1;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
