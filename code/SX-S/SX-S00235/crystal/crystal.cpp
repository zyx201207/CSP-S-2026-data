#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
bool check(int d){
	for (int i = d;i <= n;i++)
		if ((a[i] - a[i - d] + m) / d >= a[i] - a[i - 1])
			return 1;
	return 0;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1;i <= n;i++)
		scanf("%lld", &a[i]);
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++)
		a[i] += a[i - 1];
	int L = 1,R = n + 1;
	while (L + 1 < R){
		int M = (L + R) >> 1;
		if (check(M)) L = M;
		else R = M;
	}
	printf("%d\n", L);
	return 0;
}
