#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	vector <char> a;
	int n, sum = 0, ans = 0;
	cin >> n;
	if(n == 1){
		cout << 0;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		long long x;
		char c;
		cin >> x;
		cin >> c;
		sum += x;
		for(int j = 1;j <= x;j++){
			a.push_back(c);
		}
	}
	for(int i = 0;i < sum / 2;i++){
		if(a[i] != a[sum - 1 - i]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
