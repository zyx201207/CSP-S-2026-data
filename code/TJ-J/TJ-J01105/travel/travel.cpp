#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2, ans = "0000";
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) ans[0] = '1';
	if(s1[0] == s2[0] && s1[1] == s2[1] && c1 == c2) ans[1] = '1';
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]){
		if((65 <= (int)s1[2] && (int)s1[2] <= 67 && 65 <= (int)s2[2] && (int)s2[2] <= 67) || (68 <= (int)s1[2] && (int)s1[2] <= 69 && 68 <= (int)s2[2] && (int)s2[2] <= 69)){
			ans[2] = '1';
		}
	}
	int a, b;
	a = int(s1[2]);
	b = int(s2[2]);
	if(s1[0] == s2[0] && s1[1] == s2[1] && abs(a - b) == 1 && c1 == c2){
        if((65 <= (int)s1[2] && (int)s1[2] <= 67 && 65 <= (int)s2[2] && (int)s2[2] <= 67) || (68 <= (int)s1[2] && (int)s1[2] <= 69 && 68 <= (int)s2[2] && (int)s2[2] <= 69)){
			ans[3] = '1';
		}
	}
	cout << ans[0] << ans[1] << ans[2] << ans[3];
	return 0;
}
