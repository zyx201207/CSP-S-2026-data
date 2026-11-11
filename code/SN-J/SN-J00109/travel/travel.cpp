#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c = "0",s = "0",c1 = "0",s1 = "0",ans = "0";
	cin >> c >> s >> c1 >> s1;
	if(c[1] == c1[1]){
		ans = "1000";
		if(s[0] == s1[0] && s[1] == s1[1]){
			ans = "1100";
			if(s[2] <= 'C' && s1[2] <= 'C' || s[2] >= 'D' && s1[2] >= 'D'){
				ans = "1110";
				if(s[2] == 'D' || s1[2] == 'D')
						ans = "1111";
				if(s[2] <= 'C' && s1[2] <= 'C'){
					if(s[2] - s1[2] == 1 || s1[2] - s[2] == 1) 
						ans = "1111";
				}
			}
		}
	} else {
		ans = "0000";
	}
	cout << ans;
	return 0;
}
