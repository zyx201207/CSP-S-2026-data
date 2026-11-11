#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int r1;
	string r2;
	cin >> r1 >> r2;
	int x1;
	string x2;
	cin >> x1 >> x2;
	int A[10] = {0};

	if (r1 == x1) {
		A[0]
		    = 1;

		if (r2[0] == x2[0] and r2[1] == x2[1]) {
			A[1] = 1;

			if ((r2[2] == 'F' and x2[2] == 'D') or (r2[2] == 'D' and x2[2] == 'F')) {
				A[2] = 1;
				A[3] = 1;
			} else {
				if ((r2[2] == 'A' and x2[2] == 'B') or (r2[2] == 'A' and x2[2] == 'C') or (r2[2] == 'B' and x2[2] == 'C')
				        or (r2[2] == 'C' and x2[2] == 'B') or (r2[2] == 'B' and x2[2] == 'A') or (r2[2] == 'C' and x2[2] == 'A')) {
					A[2] = 1;
				}

				if ((r2[2] == 'A' and x2[2] == 'B') or (r2[2] == 'B' and x2[2] == 'A') or (r2[2] == 'D' and x2[2] == 'F')
				        or (r2[2] == 'F' and x2[2] == 'D') or (r2[2] == 'B' and x2[2] == 'C') or (r2[2] == 'C' and x2[2] == 'B')  ) {
					A[3] = 1;
				}

			}

			if (r2[-1] == x2[-1]) {
				if (r2[0] = x2[0]) {
					if ((r2[1] - '0' == x2[1] - '0' - 1) or (r2[1] - '0' - 1 == x2[1] - '0')) {
						A[3] = 1;
					}
				} else {
					if ((r2[1] == '9' and x2[1] == '0') or (r2[1] == '0' and x2[1] == '9')) {
						A[3] = 1;
					}
				}

			}


		}
	}





	for (int i = 0; i < 4; i++) {

		cout << A[i];
	}


	return 0;
}
