#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1, s1, c2, s2;
int ans[10];
signed main(){
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	for(int i = 0; i < 2; i++){
		if(c1[i] != c2[i]){
			break;
		}
		if(i == 1){
			ans[1] = 1;
		}
	}
	if(ans[1] == 1){
		for(int i = 0; i <= 1; i++){
			if(s1[i] != s2[i]){
				break;
			}
			if(i == 1){
				ans[2] = 1;
			}
		}
		char l = s1[2], r = s2[2];
		if(ans[2] == 1){
			if(l < 'D' && r < 'D' || l > 'C' && r > 'C'){
				ans[3] = 1;
			}
			if(ans[3] == 1){
				ans[4] = 1;
				if(l == 'A' && r == 'A' || l == 'C' && r == 'A'){
					ans[4] = 0;
				}
			}
		}
	}
	for(int i = 1; i <= 4; i++){
		cout << ans[i];
	}
	
	
	
	return 0;
} 
