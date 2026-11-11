#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int>a(n);

	for (int i = 0; i < n; i++) {

		cin >> a[i];
	}
	sort( a,a+n);
	for(int i=0;i<n;i++)cout<<a[0];
	return 0;
}
