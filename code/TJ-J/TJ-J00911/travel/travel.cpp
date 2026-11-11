#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	int x = s1[2] - 'A' + 1, y = s2[2] - 'A' + 1;
	if(c1 == c2){
		cout << "1";
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << "1";
			if(x <= 3 && y <= 3 || x >= 4 && y >= 4){
				cout << "1";
				if((x == y - 1) || (y == x - 1))
					cout << "1";
				else
					cout << "0";
			}
			else
				cout << "00";
		}
		else
			cout << "000";
	}
	else
		cout << "0000";
	return 0;
}
