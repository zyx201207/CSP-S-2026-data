#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 7;
unsigned long long m;
int n, a[N], dis[N];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%ull", &n, &m);
	for(int i = 1;i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	int ct = 0, ans = 0, cs = 0, as = 0;
	for(int i = 1;i <= n; i++){
		if(a[i] == a[i - 1] && i != 1){
			ans = max(ans, as + 1);
			as += 1;
			continue;
		}
		ct = 0, cs = 0, as = 0;
		int p = a[i];
		for(int j = i - 1, k = 1;j >= 1; j--, k++)
			dis[k] = a[j] - p;
		for(int j = 1;j <= i - 1; j++){
			dis[j] = -dis[j];
			if(cs + dis[j] > m)
				break;
			cs += dis[j];
			ct ++;
		}
		ans = max(ans, ct + 1);
		as = ct + 1;
	}
	printf("%lld", ans);
	return 0;
} 
