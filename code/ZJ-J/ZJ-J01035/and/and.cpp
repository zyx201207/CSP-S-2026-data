#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
int n, m;
long long a[N], ans;
bool cmp(long long a, long long b){
	return a > b;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n;i ++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1, cmp);
	ans = a[1];
	for(int i = 2;i <= m;i ++){
		ans = ans & a[i];
	}
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}