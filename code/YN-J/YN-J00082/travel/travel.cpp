#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int C1 = 0, C2 = 0;
int pai1 = 0, pai2 = 0;
int wei1 = 0, wei2 = 0;
bool zuo1 = 0, zuo2 = 0;
bool nex = 0;

bool same[4] = {0, 0, 0, 0};

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	for (int i = 0; i < c1.size(); i++) {
		C1 *= 10;
		C1 += c1[i] - '0';
	}
	for (int i = 0; i < c2.size(); i++) {
		C2 *= 10;
		C2 += c2[i] - '0';
	}
	same[0] = (C1 == C2);
	if (same[0]) {
		for (int i = 0; i < s1.size() - 1; i++) {
			pai1 *= 10;
			pai1 += s1[i] - '0';
		}
		for (int i = 0; i < s2.size() - 1; i++) {
			pai2 *= 10;
			pai2 += s2[i] - '0';
		}
		same[1] = (pai1 == pai2);
		if (same[1]) {
			wei1 = s1[s1.size() - 1] - 'A';
			if (s1[s1.size() - 1] == 'F') {
				wei1--;
			}
			wei2 = s2[s2.size() - 1] - 'A';
			if (s2[s2.size() - 1] == 'F') {
				wei2--;
			}
			zuo1 = (wei1 <= 2);
			zuo2 = (wei2 <= 2);
			same[2] = ((zuo1 && zuo2) || (!(zuo1 || zuo2)));
			if (same[2]) {
				nex = (abs(wei1 - wei2) == 1);
				same[3] = nex;
			}
		}
	}
	for (int i = 0; i <= 3; i++) {
		cout << same[i];
	}
	return 0;
}