#include <bits/stdc++.h>
using namespace std;
string c_zmx1, s_zmx1, c_zxy2, s_zxy2;     // need for cin  
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c_zmx1 >> s_zmx1 >> c_zxy2 >> s_zxy2;
	if(c_zmx1 == c_zxy2) cout << '1';
	else{cout << "0000"; return 0;} 
	if(s_zmx1[0] == s_zxy2[0] && s_zmx1[1] == s_zxy2[1]) cout << '1';
	else cout << '0';
	int flag = 0;
	if(s_zmx1[0] == s_zxy2[0] && s_zmx1[1] == s_zxy2[1] && ((int)s_zmx1[2] * (int)s_zxy2[2] == 4760 || (int)s_zmx1[2] + (int)s_zxy2[2] < 134)){cout << '1';flag = 1;} 
	else cout << '0';
	if(flag == 1 && abs((int)s_zmx1[2] - (int)s_zxy2[2]) == 1) cout << '1';
	else cout << '0';
	return 0;
} 
