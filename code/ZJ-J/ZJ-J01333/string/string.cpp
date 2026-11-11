#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, x, sum, ans;
char c;
string s;
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	while(n--){
		cin >> x >> c;
		sum += x;
		while(x--) s += c;
	}for(int i = 0; i <= sum/2 + 1; i++){
		if(s[i] != s[sum - i - 1]){
			ans++;
			s[sum - i - 1] = s[i];
		}
	}cout << ans;
	return 0;
}
