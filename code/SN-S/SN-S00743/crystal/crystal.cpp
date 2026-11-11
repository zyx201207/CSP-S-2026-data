#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000100;
long double a[maxn];
long long counting[maxn];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			counting[i] += a[i]-a[j];
		}
	}
	for(int i = 1; i <= n; i++){
		if(counting[i] <= m && m < counting[i+1]){
			cout << i;
			break;
		}
	}
	return 0;
}
