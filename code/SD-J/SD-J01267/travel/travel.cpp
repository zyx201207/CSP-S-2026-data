#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, s2, c1, c2, ans = "0000";
	cin >> s1 >> s2 >> c1 >> c2;
	if(s1 == c1){
		ans = "1000";
		if(s2[0] == c2[0] && s2[1] == c2[1]){
			ans = "1100";
			if(((s2[2] - 'A') <= ('C' - 'A') && (c2[2] - 'A') <= ('C' - 'A')) || ((s2[2] - 'A') >= ('D' - 'A') && (s2[2] - 'A') >= ('D' - 'A'))){
				ans = "1110";
				if(abs((s2[2] - 'A') - (c2[2] - 'A')) == 1) ans = "1111";
			}
		}
	}
	cout << ans << endl;
	return 0;
}
