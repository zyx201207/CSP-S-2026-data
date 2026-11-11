#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int ans[4] = {0, 0, 0, 0};
	bool tmp = true;
	for(int i = 0; i < 2; i ++) {
		if(c1[i] != c2[i]) tmp = false;
	}
	if(tmp) ans[0] = 1;
	cout << ans[0];
	tmp = true;
	for(int i = 0; i < 2; i ++) {
		if(s1[i] != s2[i]) tmp = false;
	}
	if(tmp && ans[0] == 1) ans[1] = 1;
	cout << ans[1];
	if(s1[2] <= 'C' && s2[2] <= 'C' && ans[1] == 1) ans[2] = 1;
	if(s1[2] > 'C' && s2[2] > 'C' && ans[1] == 1) ans[2] = 1;
	cout << ans[2];
	if(ans[2] == 1 && abs(s1[2] - s2[2]) == 1) ans[3] = 1;
	cout << ans[3];
	return 0;
} 
