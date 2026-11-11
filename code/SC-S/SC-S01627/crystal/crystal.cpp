#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 500050;

int n;
ll m;
ll a[N], s[N];

bool check(int x){
	for(int i = x; i <= n; i ++)
		if(a[i] * x - (s[i] - s[i - x]) <= m) return 1;
	return 0;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i ++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++)
		s[i] = s[i - 1] + a[i];
	int l = 0, r = n + 1, ans;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}