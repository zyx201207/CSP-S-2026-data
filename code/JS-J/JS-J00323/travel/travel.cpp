#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1, c2, s1, s2, ans = "";
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		ans += "1";
		string pai1 = s1.substr(0, 2), pai2 = s2.substr(0, 2);
		if(pai1 == pai2){
			ans += "1";
			string t1 = s1.substr(2, 1);
			string t2 = s2.substr(2, 1);
			if((t1 == "A" || t1 == "B" || t1 == "C") && (t2 == "A" || t2 == "B" || t2 == "C") || 
			   (t1 == "D" || t1 == "F") && (t2 == "D" || t2 == "F")){
			    ans += "1";
			    if(t1 == "A" && t2 == "B" || t1 == "B" && t1 == "A" || t1 == "B" && t2 == "C" || t1 == "C" && t2 == "B" || t1 == "D" && t2 == "F" || t1 == "F" && t2 == "D"){
			        ans += "1";
			    } else {
					ans += "0";
			    }
			}
			else{
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
