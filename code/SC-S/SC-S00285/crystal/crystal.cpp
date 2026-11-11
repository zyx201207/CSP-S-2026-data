#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;
ll n, m, a[N];
int as = 1;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = a[1]; i <= a[n]; ++i) { //a[1]~a[n]枚举 以 i 为标准
		int ct = 0;    //ct表示多少个能量一样大的水晶
		ll d = m;
		for (int j = n; j >= 1; --j) { //j表示要修改的水晶下标
			if (a[j] <= i) {
				if (i - a[j] <= d) {
					ct++;
					d -= (i - a[j]);
//					cout<<d<<"  ";
				}
			}

		}
		as = max(as, ct);
	}
	printf("%d", as);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
