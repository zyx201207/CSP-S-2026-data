#include <bits/stdc++.h>
#define int long long
using namespace std;
string c1, s1, c2, s2;
signed main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << "1";
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << "1";
			char a1 = s1[2], a2 = s2[2];
			if( (a1 == 'F' && a2 == 'D') ||
			    (a1 == 'D' && a2 == 'F') ||
				(a1 == 'C' && (a2 == 'B' || a2 == 'A')) ||
				(a1 == 'B' && (a2 == 'A' || a2 == 'C')) || 
				(a1 == 'A' && (a2 == 'B' || a2 == 'C')) ){
				cout << "1";
				if( (a1 == 'F' && a2 == 'D') ||
				    (a1 == 'D' && a2 == 'F') ||
				    (a1 - a2 == 1) ||
					(a1 - a2 == -1) ){
					cout << 1;
				} else cout << "0";
			} else cout << "00";
		} else cout << "000";
	} else cout << "0000";
	return 0;
}

