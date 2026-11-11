#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
int n;
ll m;
int cnt[N];
ll a[N], cha[N], sum[N], num[N];
ll ans(int x, ll y, int i, ll tmp){
	num[i] = y;
	if(y <= m){
		return x + 1;
	}
	return ans(x - 1, (x - 1) * cha[i] + (tmp - sum[i - 1] + sum[i - x]), i, tmp - sum[i - 1] + sum[i - x]); 
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	cha[1] = 0;
	sum[1] = 0;
	for(int i = 2; i <= n; i++){
		cha[i] = a[i] - a[i - 1];
		sum[i] = sum[i - 1] + cha[i];
		cnt[i] = 1;
	}
	cnt[1] = 1;
	num[1] = 0;
	int maxn = 1;
	for(int i = 2; i <= n; i++){
		if(cha[i] > m){
 			continue;
		}
		cnt[i] = ans(cnt[i - 1], cnt[i - 1] * cha[i] + num[i - 1], i, num[i - 1]);
		maxn = max(maxn, cnt[i]);
	}
	printf("%d", maxn);
	return 0;
}
