#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
char c[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s = "";
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= a[i]; j++){
			s += c[i];
		}
	}
	int ans = 0;
	int l = s.size();
	for (int i = 0; i < l / 2 + 1; i++){
		if (s[i] != s[l - i - 1]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
