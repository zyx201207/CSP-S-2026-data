#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool pdc = 0,pdce = 0,pdp = 0;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) {
		cout << 1;
		pdc = 1;
	} else cout << 0;
	if(s1[0] == s2[0] && s1[1] == s2[1] && pdc == 1) {
		cout << 1;
		pdp = 1;
	}else cout << 0;

	if((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') && pdp == 1) {
		cout << 1;
		pdce = 1;
	}else if((s1[1] == 'D' || s1[1] == 'F') && (s2[2] == 'D' || s2[2] == 'F') && pdp == 1) {
		cout << 1;
		pdce = 1;
	}else cout << 0;
	if((s1[2] == s2[2] - 1 || s1[2] == s2[2] + 1) && (s1[2] != 'C' && s2[2] != 'D') &&(s2[2] != 'C' && s1[2] != 'D') && pdc == 1 && pdp == 1 && pdce == 1) cout << 1;
	else cout << 0;
	return 0;
}
// T1:验证完成 预期100 
