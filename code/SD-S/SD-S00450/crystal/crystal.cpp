//Oct31==Dec25?
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
ll n, m;
ull a2[N], s2[N], ans2;
ll a[N],s[N],ans;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	bool ok = true;
	for (int i = 1;i <= n;i++) {
		scanf("%lld", &a[i]);
		if (a[i] != i) {
			ok = false;
		} 
	}
	if (ok == true) {
		for (ull i = 1;i <= n;i++)
			a2[i] = i;
		s2[0] = 0;
		for (ull i = 1;i <= n;i++){
			s2[i] = s2[i - 1] + a2[i];
		} 
		for (ull i = 1;i <= n;i++) {
			if (a2[i] * i <= s2[i] + m){ ans2 = i;}
		}
		printf("%u\n", ans2);
	} 
	else{
		sort(a + 1, a + n + 1);
		s[0] = 0;
		for (ll i = 1;i <= n;i++){
			s[i] = s[i - 1] + a[i];
			//s[i] /= i;
		} 
		for (ll i = 1;i <= n;i++) {
			if (a[i] * i <= s[i] + m){ ans = i;}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
