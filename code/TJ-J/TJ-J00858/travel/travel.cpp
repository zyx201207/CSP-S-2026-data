#include<bits/stdc++.h>

using namespace std;

string s1,s2,s3,s4,ans;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	if (s1 == s3) {
		ans += '1';
		if (s2[0] == s4[0] && s2[1] == s4[1]) {
//			cout << s2[0] << s4[0] << s2[1] << s4[1] << endl;
			ans += '1';
			char c1 = s2[2],c2 = s4[2];
			if (((c1 == 'A' || c1 == 'B' || c1 == 'C') && (c2 == 'A' || c2 == 'B' || c2 == 'C')) || ((c1 == 'D' || c1 == 'E') && (c2 == 'D' || c2 == 'E'))) {
				ans += '1';
				if ((c1 == 'A' && c2 == 'B') || (c1 == 'B' && c2 == 'C')||(c1 == 'D' && c2 == 'F')){
					ans += '1';
				}else if ((c2 == 'A' && c1 == 'B') || (c2 == 'B' && c1 == 'C')||(c2 == 'D' && c1 == 'F')){
					ans += '1';
				}else{
					ans += '0';
				}
			}else {
				ans += "00";
			}
		} else {
			ans += "000";
		}
	} else {
		ans = "0000";
	}
	cout << ans;
	return 0;
}
