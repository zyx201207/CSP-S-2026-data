#include<bits/stdc++.h>
using namespace std;
string c1, c2, w1, w2;
int sit[6][6]{
	3, 1, 2, 0, 0, 0,
	1, 3, 1, 0, 0, 0,
	2, 1, 3, 0, 0, 0,
	0, 0, 0, 3, 0, 1,
	0, 0, 0, 0, 0, 0,
	0, 0, 0, 1, 0, 3
};
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout); 
	cin >> c1 >> w1 >> c2 >> w2;
	if(c1 == c2) {
		cout << "1";
		if(w1[0] == w2[0] && w1[1] == w2[1]) {
			cout << "1";
			if(sit[w1[2] - 65][w2[2] - 65] == 1) cout << "11";
			else if(sit[w1[2] - 65][w2[2] - 65] == 2) cout << "10";
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
