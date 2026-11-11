#include <bits/stdc++.h>
using namespace std;
int c1, z1, c2, z2;
char s1, s2;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> z1 >> s1 >> c2 >> z2 >> s2;
	if (c1 != c2){
		cout << "0000";
		return 0;
	}
	else cout << "1";
	
	if (z1 != z2){
		cout << "000";
		return 0;
	}
	else cout << "1";
	
	if (s1 <= 'C' && s2 > 'C' || s2 <= 'C' && s1 > 'C'){
		cout << "00";
		return 0;
	}
	else cout << "1";

	if (s1 <= 'C' && s2 <= 'C' && abs(s1 - s2) == 1) cout << "1";
	else if (s1 >= 'D' && s2 >= 'D') cout << "1";
	else cout << "0";
	return 0;
}
//rp = INT_MAX;
