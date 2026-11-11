#include <bits/stdc++.h>
using namespace std;
long long n, m, a[600000], dim[600000][2];
long long solve1(long long k)
{
	long long i, k1 = n, k2 = n, sum = k;
	for(i = n - 1; i > 0; i --){
		if(sum - (i * dim[i][0]) <= m) break;
		sum -= (i * dim[i][0]); k1 --;
	} k1 --; sum = k;
	for(i = 1; i < n; i ++){
		if(sum - dim[i][1] <= m) break;
		sum -= dim[i][1]; k2 --;
	} k2 --;
	return (k1 < k2) ? k2 : k1;
}

long long solve(long long sum)
{
	if(sum <= m) return n;
	if(sum - dim[1][1] <= m || sum - ((n - 1) * dim[n - 1][0]) <= m) return n - 1;
	return solve1(sum);
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	long long i, sum = 0, ok = 0;
	for(i = 1; i <= n; i ++){
		scanf("%lld", &a[i]);
		if(a[i] != i) ok = 1;
	}
	sort(a, a + n + 1);
	for(i = 1; i < n; i ++){
		dim[i][0] = a[i + 1] - a[i];
	}
	dim[n - 1][1] = dim[n - 1][0];
	for(i = n - 2; i >= 0; i --){
		dim[i][1] = dim[i + 1][1] + dim[i][0];
	}
	for(i = 1; i < n; i ++) sum += dim[i][1];
	printf("%lld", solve(sum));
	return 0;
}
