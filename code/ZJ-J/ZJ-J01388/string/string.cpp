#include <bits/stdc++.h>
using namespace std;
string s = " ";
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int a;
		char c;
		cin >> a >> c;
		for (int j = 1; j <= a; j++) s += c;
	}
	long long cnt = 0, l = s.size();
	for (int i = 1; i <= l/2; i++){
		if (s[i] != s[l-i]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}