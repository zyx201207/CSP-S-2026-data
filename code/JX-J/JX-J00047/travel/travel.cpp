#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2) {
		cout << "0000";
	}
	else {
		string pa1 = "";
		string pa2 = "";
		for(int i = 0; i < 2; i++) {
			pa1 += s1[i];
		}
		for(int i = 0; i < 2; i++) {
			pa2 += s2[i];
		}
		//cout << pa1 << " " << pa2 << '\n';
		if(pa1 != pa2) {
			cout << "1000";
		}
		else {
			char pos1 = s1[2];
			char pos2 = s2[2];
			if ( (pos1 >= 'D' && pos2 < 'D') || (pos1 < 'D' && pos2 >= 'D') ) {
				 cout << "1100";
			}
			else {
				if( pos1 - pos2 != 1 && pos2 - pos1 != 1) {
					cout << "1110";
				}
				else {
					cout << "1111";
				}
			}
		}
	}
	return 0;
}
