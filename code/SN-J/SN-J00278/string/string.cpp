#include <bits/stdc++.h>
using namespace std;
long long n, a[200005], sum, ans;
char x;
string s;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> x;
		for (int j = 1; j <= a[i]; j++){
			s += x;
		}
		sum += a[i]; 
	}
	if (sum % 2 == 0){
		for (int i = 0; i < sum / 2; i++){
			if (s[i] != s[i + sum / 2]){
				ans++;
			}
		}
	}
	else{
		for (int i = 0; i <= sum / 2 - 1; i++){
			if (s[i] != s[i + sum / 2 + 1]){
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}

