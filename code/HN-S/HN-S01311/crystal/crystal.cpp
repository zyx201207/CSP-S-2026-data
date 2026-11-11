#include<bits/stdc++.h>
using namespace std;
long long n, m, a[1000010];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1);
	long long l = 1, res = 0, ans = 0, t = 0;
	for(int i = 1; i <= n; i++){
		res += t * (a[i]-a[i-1]);
		while(res > m) res -= a[i] - a[l++];
		t = i-l+1;
		ans = max(ans, t);
	}
	printf("%lld", ans);
	return 0;
}
//Viva los artistas y su amor. 
