#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
using namespace std;
const int MAXN = 5e5 + 5;
int n;
int ans;
long long m;
long long a[MAXN], s[MAXN];
inline long long slr(int l, int r){
	return s[r] - s[l - 1];
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n;i++){
		s[i] = s[i - 1] + a[i];
	}
	int j = 1;
	for(int i = 1;i <= n;i++){
		while(j <= i && a[i] * (i - j + 1) - slr(j, i) > m)j++;
		ans = max(ans, i - j + 1);
	}
	printf("%d", ans);
	return 0;
}
