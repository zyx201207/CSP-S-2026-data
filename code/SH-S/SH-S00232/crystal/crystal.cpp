#include<bits/stdc++.h>
#define inf 1000000000000000000
using namespace std;
int a[500001];
long long p[500001];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	scanf("%d %lld", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	sort(a+1, a+n+1);
	p[1] = 0;
	for(int i = 1; i < n; i++){
		__int128 t = 1LL*(a[i+1]-a[i])*i+p[i];
		if(t<=inf)p[i+1] = (long long)t;
		else p[i+1] = inf+1;
	}
	int x = upper_bound(p+1, p+n+1, m)-p-1;
	printf("%d", x);
	return 0;
}
