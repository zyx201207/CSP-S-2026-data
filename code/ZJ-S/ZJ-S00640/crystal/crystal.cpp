#include<bits/stdc++.h>
using namespace std;
int n, ans = 0;
long long m, a[500010], s[500010];
map<long long, int> mp;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		mp[a[i]]++;
		ans = max(ans, mp[a[i]]);
	}
	sort(a + 1, a + n + 1);
	s[0] = 0;
	for(int i = 1; i <= n; i++){
		s[i] = s[i - 1] + a[i];
	}
	for(int i = 1; i <= n; i++){
		int L = 0, R = i;
		while(L + 1 < R){
			int M = (L + R) >> 1;
			if(a[i] * (i - M) - (s[i - 1] - s[M - 1]) <= m){
				R = M;
			}
			else{
				L = M;
			}
		}
		ans = max(ans, i - R + 1);
	}
	printf("%d\n", ans);
	return 0;
}