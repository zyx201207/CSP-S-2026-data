#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2 * 1e5 + 5;
string s;
int n, ans;
signed main(){
	freopen("string.in", "r",stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		int a;
		string c;
		cin >> a >> c;
		for(int i = 1; i <= a; i++){
			s += c;
		}
	}
	//cout << s;
	int len = s.length();
	for(int i = 0; i < len / 2; i++){
		if(s[i] != s[len - i - 1]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
