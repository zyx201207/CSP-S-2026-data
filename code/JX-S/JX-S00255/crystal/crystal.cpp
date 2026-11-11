#include<bits/stdc++.h>
using namespace std;
const int M = 5e5 + 7;
long long a[M];
bool camp(long long a, long long b){
	return a > b;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "W", stdout);
	long long n, m, ans = 0;
	scanf("%lld%lld", &n, &m);
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
	sort(a, a + n, camp);
	for(int i = 0, j = i + 1; i < n; j++){
		long long k = m, cnt = 0;
			k -= a[i] - a[j];
			if(k < 0) break;
			cnt++;
		}
		ans = max(cnt, ans);
	}
	printf("%lld", ans);
	return 0;
}
