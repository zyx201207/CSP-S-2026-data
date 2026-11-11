#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100005;
int a[N], na, k;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> na >> k;
	
	for (int i = 1; i <= na; i++) cin >> a[i];
	
	sort(a + 1, a + na + 1, greater<int>());
	
	ll sum = a[1] & a[2]; 
	
	for (int i = 3; i <= k; i++) {
		sum = sum & a[i];
	}
	cout << sum;
	return 0; 
}
