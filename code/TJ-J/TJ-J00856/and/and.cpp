#include <bits/stdc++.h>
using namespace std;

int n, m;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	int a[n];
	
	for (int i = 0; i < n; i++){
		cin >> a[i];	
	}
	
	sort(a, a + n);
	cout << a[n - m];
	
	return 0;
}


























































































//514

//EASY
// Tanks CCF
