#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n, a[N], b[N];
//long long l = 0;
char c[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> a[i] >> c[i];
		//l += a[i];
	}
	long long ans = 0, j = 1;
	for(int i = n; i >= 1; ){
		if(j == i){
			break;
		}
		if(a[i] >= a[j]){
			if(c[i] != c[j]){
				ans += a[j];
			}
			//d += a[j];
			a[i] -= a[j];
			j++;
		}else{
			if(c[i] != c[j]){
				ans += a[i];
			}
			//d += a[i];
			a[j] -= a[i]; i--;
		}
		
	}
	cout << ans;
	return 0;
}