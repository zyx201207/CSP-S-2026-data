#include<bits/stdc++.h>
using namespace std;
string c, s, cc, ss, ans;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c >> s >> cc >> ss;
	if(c == cc){
		ans += '1';
	}else{
		ans = "0000";
		cout << ans << '\n';
		return 0;
	}
	string z, zz;
	for(int i = 0; i < 2; ++i){
		z +=s[i];
		zz += ss[i];
	}
	if(z == zz){
		ans += '1';
		if((s[2] == 'D' && ss[2] == 'C') || (ss[2] == 'D' || s[2] == 'C')){
			ans += "00";
		}else{
			ans += '1';
			if(abs(s[2] - ss[2]) == 1){
				ans += '1';
			}else{
				ans += '0';
			}
		}
	}else{
		ans += "000";
	}
	cout << ans << '\n';
	return 0;
}
