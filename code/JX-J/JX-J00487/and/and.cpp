#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int maxn = -1, s;
	for(int i = 1;i <= n;i++){
		s = a[i] & a[i + 1];
		maxn = max(maxn, s);
	}
	cout << maxn;
	return 0;
}
