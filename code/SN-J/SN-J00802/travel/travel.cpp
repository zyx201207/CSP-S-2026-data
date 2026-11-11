//SN-J00802 王欣甜 西安市铁一中学 
#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2)cout << "0000" << endl;
	else {
		if(s1[0] != s2[0] || s1[1] != s2[1])cout << "1000" << endl;
		else {
			if(!((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')))cout << "1100" << endl;
			else {
				if((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'C') || (s2[2] == 'A' && s1[2] == 'B') || (s2[2] == 'B' && s1[2] == 'C') || (s1[2] >= 'D' || s2[2] >= 'D'))cout << "1111" << endl;
				else cout << "1110" << endl;
			}
		}
	} 
} 
