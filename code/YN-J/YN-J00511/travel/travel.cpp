#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
string a;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	//输入的第一行包含四个字符串 c1, s1, c2, s2，分别表示小 R 的车票上的车厢号、座位
	//号，以及小 X 的车票上的车厢号、座位号。1true 0false
	//c1==c2
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		//ans1
		cout << "1";
		if (s1[0] == s2[0] && s1[1] == s2[1]) {//ans2
			cout << 1 ;
			if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C' && s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') {//ans3
				cout << 1;
				if (s1[2] == 'A' && s2[2] == 'B' || s1[2] == 'B' && s2[2] == 'C' || s1[2] == 'B' && s2[2] == 'A' || s1[2] == 'C'
				        && s2[2] == 'B' || s1[2] == 'D' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'D' ) {
					cout << 1;
				} else
					cout << 0;
			} else if (s1[2] == 'D' || s1[2] == 'F'  && s2[2] == 'D' || s2[2] == 'F' ) {//ans3
				cout << 1;
				if (s1[2] == 'A' && s2[2] == 'B' || s1[2] == 'B' && s2[2] == 'C' || s1[2] == 'B' && s2[2] == 'A' || s1[2] == 'C'
				        && s2[2] == 'B' || s1[2] == 'D' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'D' ) {
					cout << 1;
				} else
					cout << 0;
			} else
				cout << "00";
		}////////
		else
			cout << "000"; ///////

	} else {
		cout << "0000";
	}
	//tongyipai

	//tongyice

	//lin

	fclose(stdin);
	fclose(stdout);
	return 0;
}