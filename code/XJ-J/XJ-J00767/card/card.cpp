#include<bits/stdc++.h>
using namespace std;
const int N = 5E6;
long long int n, m, a[N], sum, k = 0, maxn = -1;
int main () {
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i ++) {
		cout << i << " ";
	}
	return 0;
}
