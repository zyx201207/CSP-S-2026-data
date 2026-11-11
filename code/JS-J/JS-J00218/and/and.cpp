#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, ma = INT_MIN, p = 0, q = 0;
	cin >> n >> m;
	int a[n + 5];
	for(int i = 1; i <= n; i++){
	    cin >> 	a[i];
	} for(int i = 1; i < n; i++){
		for(int j = i + 1; j <= n; j++){
			if((a[i] & a[j]) > ma){
				ma = (a[i] & a[j]);
				p = i;
				q = j;
			}
		}
	} a[q] = a[n];
	a[p] = a[n - 1];
	a[0] = ma;
	n -= 2;
	if(m == 2){
		cout << ma;
		return 0;
	}for(int i = 1; i < m - 1; i++){
		ma = INT_MIN;
		for(int j = 1; j <= n; j++){
			if((a[0] & a[j]) > ma){
				ma = (a[i] & a[j]);
				p = i;
			}
		} a[0] = a[p];
		a[p] = a[n];
		n--;
	} cout << a[0];
	return 0;
}
