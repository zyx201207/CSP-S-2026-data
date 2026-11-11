#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, ans;
string s;
struct ss{
	int a;
	char c;
}p[200005];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> t;
	for(int i = 1;i <= t;i++){
		cin >> p[i].a >> p[i].c;
		for(int j = 1;j <= p[i].a;j++){
			s += p[i].c;
		}
	}
	int l = 0, r = s.size() - 1;
	while(l <= r){
		if(s[l] != s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout << ans;
	return 0;
}
