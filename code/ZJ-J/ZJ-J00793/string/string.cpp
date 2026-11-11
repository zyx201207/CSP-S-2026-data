#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m, ans;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	s += " ";
	for(int i = 1, a; i <= n; i++){
		char c;
		cin >> a >> c;
		for(int j = 1; j <= a; j++){
			s += c; 
		}
	}
	m = s.size() - 1;
//	cout << s.size() << ' ';
//	cout << s << '\n';
	for(int i = 1; i <= m / 2; i++){
		if(s[i] != s[m - i + 1]) ans++;
	}
	cout << ans;
	return 0;
}
