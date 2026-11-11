#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	long long maxn = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	maxn = a[1];
	if(m == n){
		for(int i = 2; i <= n; i++){
			maxn &= a[i];
		}
		cout << maxn;
		return 0;
	}
	sort(a + 1, a + 1 + n, cmp);
	maxn = a[1];
	for(int i = 2; i <= m; i++){
		maxn &= a[i];
	}
	cout << maxn;
	return 0;
}
