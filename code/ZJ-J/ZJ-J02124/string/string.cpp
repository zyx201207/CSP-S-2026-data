#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s = "";
int n;
ll ans = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		ll a;
		char c;
		cin >> a >> c;
		while(a--) s += c;
	}for(int i = 0; i < s.size(); i++){
		int j = s.size() - 1 - i;
		if(s[i] != s[j]){
			ans++;
			s[i] = s[j];
		}
	}
	cout << ans;
	return 0;
}
