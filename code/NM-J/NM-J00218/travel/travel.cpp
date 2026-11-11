#include <bits/stdc++.h>
using namespace std;

string r_c,r_s,x_c,x_s;
string ans = "0000";

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> r_c >> r_s >> x_c >> x_s;
	
	if(r_c == x_c){
		ans[0] = '1';
		if(r_s.substr(0,2) == x_s.substr(0,2)){
			ans[1] = '1';
			if(r_s[2] == 'A' || r_s[2] == 'B' || r_s[2] == 'C'){
				if(x_s[2] == 'A' || x_s[2] == 'B' || x_s[2] == 'C'){
					ans[2] = '1';
				}
			}else if(r_s[2] == 'D' || r_s[2] == 'F'){
				if(x_s[2] == 'D' || x_s[2] == 'F'){
					ans[2] = '1';
				}
			}
		}
	}
	
	if(r_s[2] == 'A' && ans[2] == '1'){
		if(x_s[2] == 'B'){
			ans[3] = '1';
		}
	}else if(r_s[2] == 'B' && ans[2] == '1'){
		if(x_s[2] == 'A' || x_s[2] == 'C'){
			ans[3] = '1';
		}
	}else if(r_s[2] == 'C' && ans[2] == '1'){
		if(x_s[2] == 'B'){
			ans[3] = '1';
		}
	}else if(r_s[2] == 'D' && ans[2] == '1'){
		if(x_s[2] == 'F'){
			ans[3] = '1';
		}
	}else if(r_s[2] == 'F' && ans[2] == '1'){
		if(x_s[2] == 'D'){
			ans[3] = '1';
		}
	}
	cout << ans;
	return 0;
}
