#include <bits/stdc++.h>
using namespace std;

string deng1, idd1, deng2, idd2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> deng1 >> idd1 >> deng2 >> idd2;
//	string pai1,lie1,pai2,lie2;
//	for(int i=0;i<2;i++){
//		pai1[i] = idd1[i];
//		pai2[i] = idd2[i];
//	}
//	lie1=idd2[2];
//	lie2=idd2[2];
	int lie1, lie2;
	lie1 = idd1[2] - 64;
	lie2 = idd2[2] - 64;
	if (deng1 == deng2) {
		cout << "1";
		if ((idd1[1] == idd2[1]) && (idd1[0] == idd2[0])) {
			cout << "1";
			if (lie1 <= 3 && lie2 <= 3) {
				cout << "1";
				if ((lie1 + 1 == lie2) || (lie1 - 1 == lie2)) {
					cout << "1";
				} else {
					cout << "0";
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

	fclose(stdin);
	fclose(stdout);
	return 0;
}