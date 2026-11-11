#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;
long long m, a[50005];

bool cmp(int a, int b) {
	return b > a;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	if (m == 0) {
		for (int i = 1; i <= n; i++) {
			int mid = n / 2;
			if ((a[mid - i] == a[mid] && a[mid + i] == a[mid]) || (a[mid - i] == a[mid] || a[mid + i] == a[mid])) {
				ans++;
			}
		}
		cout << ans;
		return 0;
	}
	return 0;
	//weijojifewiojweijfjiiiiiiiiwoiefjowijefoijwpofqpoij24pf9 cq	1234 f9uh4n3uj4fpa;wenoaiuwn34fuwepoiwuefnoiaupwenfpoinwaeopifanwoinef
	//weijojifewiojweijfjiiiiiiiiwoiefjowijefoijwpofqpoij24pf9 cq	1234 f9uh4n3uj4fpa;wenoaiuwn34fuwepoiwuefnoiaupwenfpoinwaeopifanwoinef
	//iojweijfjiiiiiiiiwoiefjowijefoijwpofqpoij24pf9 cq	1234 f9uh4n3uj4fpa;wenoaiuwn34fuwepoiwuefnoiaupwenfpoinwaeopifanwoinef//weijojifewiojweijfjiiiiiiiiwoiefjowijefoijwpofqpoij24pf9 cq	1234 f9uh4n3uj4fpa;wenoaiuwn34fuwepoiwuefnoiaupwenfpoinwaeopifanwoinef//weijojifewiojweijfjiiiiiiiiwoiefjowijefoijwpofqpoij24pf9 cq	1234 f9uh4n3uj4fpa;wenoaiuwn34fuwepoiwuefnoiaupwenfpoinwaeopifanwoinef//weijojifewiojweijfjiiiiiiiiwoiefjowijefoijwpofqpoij24pf9 cq	1234 f9uh4n3uj4fpa;wenoaiuwn34fuwepoiwuefnoiaupwenfpoinwaeopifanwoinef
}