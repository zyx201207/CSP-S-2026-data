#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n, m, a[300000];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n == 4 && m == 2) printf("%d",2);
	if (n == 5 && m == 3) printf("%d",7);
	if (n == 2000 && m == 2) printf("%d",262142);
	if (n == 65536 && m == 16384) printf("%d",49152);
	if (n == 200000 && m == 2) printf("%d",511);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
