#include<bits/stdc++.h>
using namespace std;
const int N = 1e8 + 5;
int n;
char c[N];
int a[N];
char shu[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int k = 0;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= a[i]; j++) {
			shu[++k] = c[i];
		}
	}
	int cnt = 0;
	for (int i = 1; sum % 2 ==0 ? i <= (sum + 1) / 2 : i < (sum + 1) / 2; i++) {
//		cout << i << " " << sum - i + 1 << endl;
		if(shu[i] == shu[sum - i + 1]) {
			cnt++;
		}
	}
	cout << sum / 2 - cnt;
	return 0;
}