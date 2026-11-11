#include<bits/stdc++.h>
using namespace std;
int q, ans;
string s;
int main(){
	cin >> q;
	int cnt = 0;
	while(q--){
		int n;
		char c;
		cin >> n >> c;
		for(int i = 1; i <= n; i++){
			s += c;
			cnt++;
		}
	}
	int ma, t, p;
	for(int i = 0; i < cnt; i++){
			for(int j = 0; j < cnt; j++){
				if(s[i] == s[j]){
					t++;
				}
			}
			if(t > ma){
				ma = t;
				p = i;
			}
		}
	if(cnt % 2 != 0){
		int mid = cnt / 2;
		if(p < mid){
			for(int i = mid+1; i <= cnt - 1; i++){
				if(s[i] != s[p]){
					s[i] = s[p];
					ans++;
				}
			}
		}
		if(p > mid){
			for(int i = 0; i < mid; i++){
				if(s[i] != s[p]){
					s[i] = s[p];
					ans++;
				}
			}
		}
	}
	if(cnt % 2 == 0){
		int mid = cnt / 2;
		if(p < mid){
			for(int i = mid; i <= cnt - 1; i++){
				if(s[i] != s[p]){
					s[i] = s[p];
					ans++;
				}
			}
		}
		if(p > mid){
			for(int i = 0; i < mid; i++){
				if(s[i] != s[p]){
					s[i] = s[p];
					ans++;
				}
			}
		}
	
	}
	cout << ans;
	return 0;
}