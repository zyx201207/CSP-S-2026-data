#include <bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int n;
long long ans;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		cin >> c[i];
	}
	int i = 1;
	while(i != n){
		if (c[i] != c[n]){
			ans += min(a[i], a[n]);
			//cout << ans << endl; 
		}
		if (a[i] > a[n]){
			a[i] = a[i] - a[n];
			n--;
		}
		else if (a[i] < a[n]){
			a[n] = a[n] - a[i];
			i++;
		}
		else{
			if (i + 1 == n) break;
			i++;
			n--;
		}
	}
	cout << ans;
	return 0;
}
