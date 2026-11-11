#include <bits/stdc++.h>
using namespace std;
string ache, bche, asit, bsit;
bool sce, scp, syc, xl;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> ache >> asit >> bche >> bsit;
	ios::sync_with_stdio(0);
	cin.tie(0);

	if (ache == bche) {
		sce = 1;

		if (asit[0] == bsit[0] && asit[1] == bsit[1]) {
			scp = 1;


			if ((asit[2] == 'A' && bsit[2] == 'B') || (asit[2] == 'A' && bsit[2] == 'C') ||
			        (asit[2] == 'B' && bsit[2] == 'C') || (asit[2] == 'D' && bsit[2] == 'F') ||
			        (bsit[2] == 'A' && asit[2] == 'B') || (bsit[2] == 'A' && asit[2] == 'C') ||
			        (bsit[2] == 'B' && asit[2] == 'C') || (bsit[2] == 'D' && asit[2] == 'F')) {
				syc = 1;

				if ((asit[2] == 'A' && bsit[2] == 'B') || (asit[2] == 'B' && bsit[2] == 'C') ||
				        (asit[2] == 'D' && bsit[2] == 'F') ||
				        (bsit[2] == 'A' && asit[2] == 'B') || (bsit[2] == 'B' && asit[2] == 'C') ||
				        (bsit[2] == 'D' && asit[2] == 'F')) {
					xl = 1;
				}
			}

		}
	}

	cout << sce << scp << syc << xl;
	return 0;
}
