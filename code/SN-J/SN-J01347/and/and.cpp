#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 2e5 + 5;
int a[N], n, m, maxx=0;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort (a+1, a+n+1);
	for (int i = 1;i <= n-m+1;i++){
		int k = a[i];
		for (int j = i+1;j <= i+m-1;j++)
			k &= a[j];
		maxx = max(maxx, k);
	}
	cout << maxx;
	return 0;
}
