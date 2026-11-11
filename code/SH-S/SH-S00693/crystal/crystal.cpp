#include <bits/stdc++.h>
using namespace std;
int n;
long long m, a[500005], cnt, ans, sum = 1ll;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	cnt = m;
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++){
		if((i - 1) * (a[i] - a[i - 1]) > cnt){
			cnt -= (cnt / (i - 1)) * (i - 1);
			sum = i - 1;
			break;
		}	else{
			cnt -= (i - 1) * (a[i] - a[i - 1]);
			sum = i;
		}
	}
	cout << sum;
}
