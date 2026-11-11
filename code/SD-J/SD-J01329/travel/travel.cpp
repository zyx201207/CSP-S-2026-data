#include<bits/stdc++.h>
using namespace std;
bool cmp(char s1, char s2) {
	if(s1 == 'A' && s2 == 'C') return 0;
	if(s1 == 'C' && s2 == 'A') return 0;
	return 1;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2)
		cout << "0000";
	else {
		cout << "1";
		if(s1[0] != s2[0] || s1[1] != s2[1])
			cout << "000";
		else {
			cout << "1";
			bool r1, r2;
			if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')
				r1 = 1;
			else
				r1 = 0;
			if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')
				r2 = 1;
			else 
				r2 = 0;
			if(r1 != r2) cout << "00";
			else {
				cout << "1";
				if(cmp(s1[2], s2[2])) cout << 1;
				else cout << 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
