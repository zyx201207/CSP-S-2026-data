# include <bits/stdc++.h>

using namespace std;

long long n, num, cnt, ans, a[210000], j;
char c, kc;
string s, ss;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++){
		cin >> num;
		cin >> c;
		cnt += num;
		for (int k = 1; k <= num; k ++){
			ss += c;
		}
	}
	if (s.size() == 1){
		cout << 0;
		return 0;
	}
	if (s.size() == 2){
		cout << min(a[1], a[2]);
		return 0;
	}
	
	for (int i = 0; i <= (cnt / 2); i ++){
		if (ss[i] != ss[cnt - i - 1]){
			ans ++;
		}
	}
	cout << ans;
	return 0;
}
