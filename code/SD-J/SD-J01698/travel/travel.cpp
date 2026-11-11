#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string n, m, p, q, ans = "----";
	cin >> n >> m >> p >> q;
	if (n == p){
		if (m[0] == q[0] && m[1] == q[1]){
			if (m[2] - 'A' <= 2 && q[2] - 'A' <= 2){
				if (abs(m[2] - q[2]) == 1){
					ans = "1111";
				} else {
					ans = "1110";
				}
			} else if (m[2] - 'A' >= 3 && q[2] - 'A' >= 3){
				ans = "1111";
			} else {
				ans = "1100";
			}
		} else {
			ans = "1000"; 
		}
	} else {
		ans = "0000";
	}
	cout << ans;
	return 0;
}
