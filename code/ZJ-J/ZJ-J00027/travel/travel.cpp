#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2 ;
	string ans = "0000" ;
	if ( c1 == c2) {
		ans[0] = '1' ;
		if ( s1[0] == s2[0] && s1[1] == s2[1] ) {
			ans[1] = '1' ;
			if ( ( (int(s1[2]) <= 67) && (int(s2[2]) <= 67 ) ) || ( (int(s1[2]) > 67) && (int(s2[2]) > 67 ) ) ){
				ans[2] = '1' ;
				if ( abs( int(s1[2]) - int(s2[2]) ) == 1) {
					ans[3] = '1' ;
				}
			}
		}
	}
	cout << ans << "\n" ;
	return 0;
}