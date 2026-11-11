#include<bits/stdc++.h>
using namespace std;
int n;
long long ans, pos;
string s, t;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x;
		char c;
		scanf("%d %c", &x, &c);
		for(int j = 1; j <= x; j++){
			s += c;
		}
	}
	long long l = s.size();
	for(int i = l - 1; i >= 1; i--){
		t += s[i];
	}
	if(t == s) cout << 0;
	else{
		for(int i = 0; i <= l / 2 - 1; i++){
			if(s[i] != t[i]){
				ans++;
				s[i] = t[i];
			}
		}
		cout << ans;
	}
	return 0;
}