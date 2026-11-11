#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

int r = 18;
int c = 6;
string seatLst[18][6];

void init() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			string newSeat = "";

			if (j == 3) {
				seatLst[i][j] = "X";
				continue;
			}

			if (i >= 9) {
				newSeat += to_string(i + 1);
			} else {
				newSeat += "0" + to_string(i + 1);
			}
			if (j == 0)
				newSeat += "A";
			else if (j == 1)
				newSeat += 'B';
			else if (j == 2)
				newSeat += 'C';
			else if (j == 4)
				newSeat += 'D';
			else if (j == 5)
				newSeat += 'F';

			seatLst[i][j] = newSeat;
		}
	}
}

int charToInt(char c) {
	if (c == 'A') {
		return 0;
	}
	if (c == 'B') {
		return 1;
	}
	if (c == 'C') {
		return 2;
	}
	if (c == 'D') {
		return 3;
	}
	if (c == 'E') {
		return 4;
	}
	if (c == 'F') {
		return 5;
	}

	return -1;
}

int myStoi(string s) {
	if (s == "01")
		return 1;
	if (s == "02")
		return 2;
	if (s == "03")
		return 3;
	if (s == "04")
		return 4;
	if (s == "05")
		return 5;
	if (s == "06")
		return 6;
	if (s == "07")
		return 7;
	if (s == "08")
		return 8;
	if (s == "09")
		return 9;
	if (s == "10")
		return 10;
	if (s == "11")
		return 11;
	if (s == "12")
		return 12;
	if (s == "13")
		return 13;
	if (s == "14")
		return 14;
	if (s == "15")
		return 15;
	if (s == "16")
		return 16;
	if (s == "17")
		return 17;
	if (s == "18")
		return 18;

	return -1;
}

int main() {
	const char *inFile = "travel.in";
	const char *outFile = "travel.out";
	freopen(inFile, "r", stdin);
	freopen(outFile, "w", stdout);

	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;

	init();

	if (c1 == c2)
		cout << 1;
	else {
		cout << 0 << 0 << 0 << 0;
		return 0;
	}

	int num1, num2;
	char seat1, seat2;
	int seat1Int, seat2Int;
	string tmp = "";
	string tmp2 = "";
	for (int i = 0; i < 2; i++) {
		tmp += s1[i];
		tmp2 += s2[i];
	}
	num1 = myStoi(tmp);
	num2 = myStoi(tmp2);
	seat1 = s1[2];
	seat2 = s2[2];
	seat1Int = charToInt(seat1);
	seat2Int = charToInt(seat2);

	if (num1 == num2)
		cout << 1;
	else {
		cout << 0 << 0 << 0;
		return 0;
	}

	if (seat1Int <= 2 && seat2Int <= 2) {
		cout << 1;
	} else if (seat1Int > 2 && seat2Int > 2) {
		cout << 1;
	} else {
		cout << 0 << 0;
		return 0;
	}

	// Ñ°ÕÒ1ºÅÎ»ÖÃ
	bool foundFlag = false;
	for (int i = 0; i < r; i++) {
		if (foundFlag)
			break;
		for (int j = 0; j < c; j++) {
			if (foundFlag)
				break;
			if (seatLst[i][j] == s1) {
				foundFlag = true;

				// ÏòËÄÖÜÑ°ÕÒ2ºÅ
				int dir[4][2] = {
					{0, 1}, {0, -1}, {1, 0}, {-1, 0}
				};
				for (int n = 0; n < 3; n++) {
					int nx = i + dir[n][0];
					int ny = j + dir[n][1];
					if (nx < 0 || ny < 0 || nx >= r || ny >= c)
						continue;
					if (seatLst[nx][ny] == s2) {
						cout << 1;
						return 0;
					}
				}
			}
		}
	}

	cout << 0;

	return 0;
}