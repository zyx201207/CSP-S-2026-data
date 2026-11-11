#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,x[200005],ans;
char c[200005];
string s;
bool f = true,ff = true;
bool is_hui(string s){
	for(int i = 0;i < s.size() - 1;){
		int j = s.size() - 1;
		if(s[i] != s[j]) return false;
		i++;j--;
	}
	return true;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> x[i] >> c[i];
	}
	for(int i = 1;i <= n;i++) if(c[i] != c[i + 1]) f = false;
	if(f == true) {cout << 0 << "\n";return 0;}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= x[i];j++){
			s = s + c[i];
		}
	}
	if(is_hui(s) == true) {cout << 0 << "\n";return 0;}
	
	return 0;
}
