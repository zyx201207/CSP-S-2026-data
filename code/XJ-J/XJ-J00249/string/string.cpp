#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, a[N], sum;
char b[N]; 
signed main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i]>> b[i]; 
	int l = 1, r = n;
	while (l < r){
		if (b[l] != b[r]){
			if (a[l] > a[r]){
				a[l] -= a[r];
				sum += a[r];
				r --;
			}
			else if (a[l] < a[r]){
				a[r] -= a[l];
				sum += a[l];
				l ++;
			}
			else{
				sum += a[r];
				r --;
				l ++;
			}
		}
		else{
			if (a[l] > a[r]){
				a[l] -= a[r];
				r --;
			}
			else if (a[l] < a[r]){
				a[r] -= a[l];
				l ++;
			}
			else{
				r --;
				l ++;
			}
		}
	} 
	cout << sum;

return 0;
}
