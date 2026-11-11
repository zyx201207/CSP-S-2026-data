#include <bits/stdc++.h>
using namespace std;
string r1, r2, x1, x2;
map <char, int> mp;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	mp['A'] = 1;
	mp['B'] = 1;
	mp['C'] = 1;
	mp['D'] = 2;
	mp['F'] = 2;
	cin >> r1 >> r2 >> x1 >> x2;
	if(r1 != x1){
		cout << "0000" << endl;
		return 0;
	}
	cout << "1";
	if(r2[0] == x2[0] && r2[1] == x2[1]){
		cout << "1";
		if(mp[r2[2]] == mp[x2[2]]){
			cout << "1";
			if(mp[r2[2]] == 2){
				cout << "1";
			}
			else if(r2[2] == 'A' && x2[2] =='B'){
				cout << "1";
			}
			else if(r2[2] == 'B' && x2[2] =='A'){
				cout << "1";
			}
			else if(r2[2] == 'B' && x2[2] =='C'){
				cout << "1";
			}
			else if(r2[2] == 'C' && x2[2] =='B'){
				cout << "1";
			}
			else{
				cout << "0";
			}
		}
		else{
			cout << "00";
		}
	}
	else{
		cout << "000" << endl;
	}
	return 0;
}
