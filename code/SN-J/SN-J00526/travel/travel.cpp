#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	if(s1[0] == s2[0] && s1[1] == s2[1]) cout << 1;
	else {
		cout << "000";
		return 0;
	}
	char s11 = s1[2],s22 = s2[2];
	if(s11 > s22) swap(s11,s22);
	if(s11 == 'A' && s22 == 'B') cout << "11";
	else if(s11 == 'A' && s22 == 'C') cout << "10";
	else if(s11 == 'A' && s22 == 'D') cout << "00";
	else if(s11 == 'A' && s22 == 'F') cout << "00";
	else if(s11 == 'B' && s22 == 'C') cout << "11";
	else if(s11 == 'B' && s22 == 'D') cout << "00";
	else if(s11 == 'B' && s22 == 'F') cout << "00";
	else if(s11 == 'C' && s22 == 'D') cout << "00";
	else if(s11 == 'C' && s22 == 'F') cout << "00";
	else if(s11 == 'D' && s22 == 'F') cout << "11";
	return 0;
}
