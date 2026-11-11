#include <bits/stdc++.h>
using namespace std;

int main() {
	string s1, s2, z1, z2;
	cin >> s1 >> s2 >> z1 >> z2;
	int f = 1;
	string A = "A", B = "B", C = "c", D = "D", F = "F";

	for (int i = 1; i <= 4; i++) {

		if (s1 != z1) {
			cout << "0000";
			return 0;
		}

		if (s1 == z1 && i == 1) {
			cout << 1;
		} else if (s2[0] == z2[0] && s2[1] == z2[1] && i == 2) {
			cout << 1;
		} else if (s2[0] != z2[0] || s2[1] != z2[1] && i == 2) {
			cout << "000";
			return 0;
		} else if (s2[2] == A[0] && z2[2] != A[0] && z2[2] != B[0] && z2[2] != C[0] && i == 3) {
			cout << "00";
			return 0;
		} else if (s2[2] == B[0] && z2[2] != A[0] && z2[2] != B[0] && z2[2] != C[0] && i == 3) {
			cout << "00";
			return 0;
		} else if (s2[2] == C[0] && z2[2] != A[0] && z2[2] != B[0] && z2[2] != C[0] && i == 3) {
			cout << "00";
			return 0;
		} else if (s2[2] == D[0] && z2[2] != D[0] && z2[2] != F[0] && i == 3) {
			cout << "00";
			return 0;
		} else if (s2[2] == F[0] && z2[2] != D[0] && z2[2] != F[0] && i == 3) {
			cout << "00";
			return 0;
		} else if (f = 1 && i == 3) {
			cout << 1;
		} else if (s2[2] == D[0] || s2[2] == F[0] || s2[2] == B[0] || z2[2] == B[0] && i == 4) {
			cout << 1;
		} else
			cout << "0";

	}




	return 0;
}
