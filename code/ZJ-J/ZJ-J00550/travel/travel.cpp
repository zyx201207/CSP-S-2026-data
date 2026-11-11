#include <bits/stdc++.h>
#include <string>
using namespace std;
string s1, s2, s3, s4, s5, s6;
char c1, c2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1 == s3) cout << "1";
	else{
		cout << "0000";
		return 0;
	}
	s5 = s2[0] + s2[1];
	s6 = s4[0] + s4[1];
	if(s5 == s6) cout << "1";
	else{
		cout << "000";
		return 0;
	}
	c1 = s2[2];
	c2 = s4[2];
	if(c1 > c2) swap(c1, c2);
	if(c2 == 'F' && c1 == 'D') cout << "11";
	else if(c2 == 'C' && c1 == 'B' || c2 == 'B' && c1 == 'A') cout << "11";
	else if(c2 == 'C' && c1 == 'A') cout << "10";
	else cout << "00";
	return 0;
}
