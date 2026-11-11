#include <bits/stdc++.h>
using namespace std;

int mun[] = {0, 1, 0, 0, 0};
double A, B, C, D, F;

double ant[] = {A, B, C, D, F};
double sum[90];

int main() {
	freopen("trave.in", "r", stdin);
	freopen("trave.out", "w", stdout);
	int s1, s2;
	int c1, c2;
	int a = 0, b = 1, s, x, a1, a2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
		mun[0] = 1;
	else
		mun[0] = 0;

	for (int i = 1; i <= 90; i++) {
		if (a < 6) {

			for (int j = 1; j <= 5; j++) {
				sum[i] = j + ant[b];//ÅÅ³öÐòºÅ


				if (sum[i] == s1) {
					if (b <= 3)
						a1 = 1;
					else
						a1 = 0;
					s = i ;
				}
				if (sum[i] == s2) {
					if (b <= 3)
						a2 = 1;
					else
						a2 = 0;
					x = i ;
				}
				a++;
				b++;

			}
		} else {
			a = 1;

		}
	}

	if (s / 5 == x / 5) {
		mun[1] = 1;
		if (s - x == 1)
			mun[3] = 1;
		if (x - s == 1)
			mun[3] = 1;
		else
			mun[3] = 0;
		if (a1 = a2) {
			mun[2] = 1;

		} else
			mun[2] = 0;
	} else {
		mun[1] = 0;
		mun[2] = 0;
	}
	cout << mun[0] << mun[1] << mun[2] << mun[3] ;

}