#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+10;
pair<int, char> a[MAXN];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	string s, ss;
	a[0].first = 0;
	a[0].second = ' ';
	for(int i = 1; i <= n; i++){
		cin >> a[i].first >> a[i].second;
		ss += a[i].second;
	}
	// cout << ss << " " << n;
	long long ans1 = 0;
	for(long long i = 0; i*2 < n; i++){
		if(ss[i] != ss[n-i-1]){
			ans1++;
		}
	}
	// cout << ans1 << endl;
	bool flag1 = true;
	for(int i = 1; i <= n; i++){
		if(i != 1 && a[i].first != a[i-1].first)
			flag1 = false;
	}
	if(flag1){
		cout << ans1 * a[1].first;
		return 0;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= a[i].first; j++){
			s += a[i].second;
		}
	}
	
	bool flag = true;
	for(int i = 1; i <= n; i++){
		if(i != 1 && a[i].second != a[i-1].second)
			flag = false;
	}
	if(flag){
		cout << 0;
		return 0;
	}
	
	// cout << s << s.size();
	long long ans = 0;
	long long len = s.size();
	for(long long i = 0; i*2 < len; i++){
		if(s[i] != s[len-i-1]){
			ans++;
		}
	}
	
	cout << ans;
	
	return 0;
}
// 4 2 c 3 b 2 a 1 b












