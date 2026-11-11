#include<bits/stdc++.h>
using namespace std; 
bool f;
string ans = "0000", a, b, c, d, n = "ABCDF"; 
int main(){
	freopen("travel.in", "in", stdin);
	freopen("travel.out", "out", stdout);
	cin>> a >> b >> c >> d;
	if (a == c){
		ans = "1000";
		for (int i = 0; i < 3; i++){
			if (i < 2 && b[i] != d[i]) f = 1;
		}
		string g = b, e = d;
		if (!f){
			ans = "1100";
			if ((g[2] == n[0] || g[2] == n[1] || g[2] == n[2]) && (e[2] == n[0] || e[2] == n[1] || e[2] == n[2])){
				ans = "1110";
				if (g[2] == n[0] && e[2] == n[1]) {
					ans = "1111";
				}
				if (g[2] == n[1] && (e[2] == n[0] || e[2] == n[2])) {
					ans = "1111";
				}
				if (g[2] == n[2] && e[2] == n[1]) {
					ans = "1111";
				}
			}
			if ((g[2] == n[3] || g[2] == n[4]) && (e[2] == n[3] || e[2] == n[4])){
				ans = "1111";
			}
		}
	}
	cout<< ans;
	return 0;
}
