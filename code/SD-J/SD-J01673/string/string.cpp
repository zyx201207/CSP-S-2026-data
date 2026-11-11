#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
long long cnt;
char c[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	} 
	int l = 1, r = n;
	while (l < r){
		if (a[l] == a[r]){
			if (c[l] != c[r]){
				cnt += a[l];
				a[r] = 0;
			}
			l++;
			r--;
		}
		else{
			if (c[l] != c[r]){
				if (a[l] > a[r]){
					cnt += a[r];
					a[l] = a[l] - a[r];
					a[r] = 0;
					r--;
				}
				else{
					cnt += a[l];
					a[r] = a[r] - a[l];
					a[l] = 0;
					l++;
				}
			}
			else{
				if (a[l] > a[r]){
					a[l] = a[l] - a[r];
					a[r] = 0;
					r--;
				}
				else{
					a[r] = a[r] - a[l];
					a[l] = 0;
					l++;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}
