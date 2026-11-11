#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, m, cnt = 0;
	long long ans = 0;
	char a;
	string s = "";
	string t = "";
	cin >> n;
	cin >> m >> a;
	if(m >= 20){
		ans += m;
		for(int i = 2; i <= n; i++){
			cin >> m >> a;
			ans += m;
		} cout << (ans / 2);
	}else{
		for(int j = 1; j <= m; j++){
				s[cnt] = a;
				cnt++;
	    } for(int i = 2; i <= n; i++){
			cin >> m >> a;
			for(int j = 1; j <= m; j++){
				s[cnt] = a;
				cnt++;
			}
		} for(int i = 0; i < cnt; i++){
			t[cnt - 1 - i] = s[i];
		} for(int i = 0; i <= (cnt - 2)/2; i++){
			if(s[i] != t[i]){
				ans++;
			}
		} cout << ans;
	}
    return 0;	
}

