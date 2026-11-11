#include <bits/stdc++.h>
using namespace std;

int Tests = 1;

constexpr int N = 5e5 + 10;

int ca; // CrystalAttempts
long long moa; // MaxOperationAttempts
long long ecp[N]; // EveryCrystalPower

long long mctca = 1; // MaxCrystalToCraftAttempts

void solve(istream &in, ostream &out);

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

//	cin >> Tests;
	while (Tests--) {
		solve(cin, cout);
	}
	return 0;
}

void solve(istream &in, ostream &out) {
	in >> ca >> moa;
	for (int i = 1; i <= ca; i++) {
		in >> ecp[i];
	}

	sort(ecp + 1, ecp + ca + 1);

	if (ca <= 5e3 || moa <= 1e8) {
		for (int i = 1; i <= ca; i++) {
			int j = i - 1;
			long long h = 0;

			while (j > 0 && h <= moa) {
				h += ecp[i] - ecp[j];
				--j;
			}

			mctca = max(mctca, static_cast<long long>(i - j));
		}
		out << mctca;
	} else if (ecp[2] - ecp[1] == ecp[3] - ecp[2] && ecp[3] - ecp[2] == ecp[ca] - ecp[ca - 1]) {
		int h = 0;
		for (int i = ca - 1; i >= 1; i--) {
			h += ecp[ca] - ecp[i];

			if (h > moa) {
				mctca = ca - i;
				break;
			}
		}
		out << mctca;
	} else {
		for (int i = 1; i <= ca; i++) {
			int j = i - 1;
			long long h = 0;

			while (j > 0 && h <= moa) {
				h += ecp[i] - ecp[j];
				--j;
			}

			mctca = max(mctca, static_cast<long long>(i - j));
		}
		out << mctca;
	}
}
