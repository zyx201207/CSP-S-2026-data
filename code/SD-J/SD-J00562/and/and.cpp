#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
map <int, int> mp;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, h = 0, maxn = -1e9;
	cin >> n >> m;
	if(m > n / 2){
		h = n - m;
	}else h = m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i ++){
		for(int j = i + 1; j <= n; j ++){
			maxn = max(maxn, a[i] & a[j]);
		}
	}
	cout << maxn;
	return 0;
}
