#include<bits/stdc++.h>
using namespace std;

long long n, m, k, l, a[500005], s[500005];
int ans = 1;

int check(int x){
	int L = 0, R = x + 1;
	if(a[x] * x - s[x] <= m){
		return x;
	}
	while(L + 1 < R){
		int M = (L + R) / 2;
		if(a[x] * (x - M + 1) - (s[x] - s[M - 1]) <= m){
			R = M;
		}
		else{
			L = M;
		}
	}
	return x - R + 1; 
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n;i++){
		s[i] = s[i - 1] + a[i];
	}
	for(int i = 1;i <= n;i++){
		ans = max(check(i), ans);
	}
	printf("%lld", ans);
	return 0;
}
