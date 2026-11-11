#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin >> n;
	for(int i = 1;i <= n;i++){
		char c;int x;
		cin >> x >> c;
		for(int i = 1;i <= x;i++){
			s += c;
		}
	}
	int ans = 0;
	for(int i = 0;i < s.size()/2;i++){
		if(s[i] != s[s.size()- 1-i])ans++;
	}
	cout << ans;
	return 0;
}
