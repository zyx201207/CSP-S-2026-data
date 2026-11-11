#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int chexiang1, chexiang2;
	string zuoweihao1, zuoweihao2;
	cin >> chexiang1 >> zuoweihao1 >> chexiang2 >> zuoweihao2;
	if (chexiang1 == chexiang2) {
		cout << '1';
		if (zuoweihao1[0] == zuoweihao2[0] && zuoweihao1[1] == zuoweihao2[1]) {
			cout << '1';
			if (( (zuoweihao1[2] == 'A' || zuoweihao1[2] == 'B' || zuoweihao1[2] == 'C') && (zuoweihao2[2] == 'A' || zuoweihao2[2] == 'B' || zuoweihao2[2] == 'C')) || ((zuoweihao1[2] == 'D' || zuoweihao1[2] == 'E') && (zuoweihao2[2] == 'D' || zuoweihao2[2] == 'E'))) {
				cout << '1';
				if ((zuoweihao1[2] == 'A' && zuoweihao2[2] == 'B') || (zuoweihao1[2] == 'B' && zuoweihao2[2] == 'A') || (zuoweihao1[2] == 'B' && zuoweihao2[2] == 'C') || (zuoweihao1[2] == 'C' && zuoweihao2[2] == 'B') || (zuoweihao1[2] == 'D' && zuoweihao2[2] == 'E') || ((zuoweihao1[2] == 'E' && zuoweihao2[2] == 'D'))) {
					cout << '1';
				} else {
					cout << '0';
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}