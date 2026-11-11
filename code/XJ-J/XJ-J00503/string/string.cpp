#include <bits/stdc++.h>
using namespace std;

string s = "";

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n;
	cin >> n;
	while(n--) {
		long long x;
		char c;
		cin >> x >> c;
		while(x--) {
			s += c;
		}
	}
	
	long long len = s.size();
	long long j = len - 1;
	int ans = 0;
	for(int i = 0; i < len; i++) {
		if(i > j) {
			break;
		}
		
		if(s[i] != s[j]) {
			ans++;
		}
		
		j--;
	}
	
	cout << ans;
	
	return 0;
}