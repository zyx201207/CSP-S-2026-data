#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 3;
int n,m,a[N];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	cout << *max_element(a + 1,a + 1 + n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
