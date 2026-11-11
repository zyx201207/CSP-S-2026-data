#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int n, a, ans, size;
char c;
stringstream ss;
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a >> c;
		std::string s(a, c);
	    ss << s;
	    size += a;
	}
	string s1 = ss.str();
	int mid = size / 2;
	for(int i = 0;i < mid;i++){
		if(s1[i] != s1[size - i]) ans++;
	}
	cout << ans;
	return 0;
}
