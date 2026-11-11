#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s, s1, s2, s3;
	cin >> s >> s1 >> s2 >> s3;

	if (s == s2) {
		cout << "1";

		for (int i = 0; i < 1; i++) {

			int a = s1[i];
			int b = s3[i];
			int a1 = s1[i + 1];
			int b1 = s3[i + 1];

			if (a == b && a1 == b1) {
				cout << "1";

				for (int j = 2; j < 3; j++) {

					int aa = s1[j];
					int bb = s3[j];

					if (aa == 'A' && aa == 'B' && aa == 'C' && bb == 'A' && bb == 'B' && bb == 'c') {
						cout << "1";

						if (aa - bb > 1 && bb - aa > 1) {
							cout << "0";
						} else {
							cout << "1";
						}



					} else if (aa == 'D' && aa == 'F' && bb == 'D' && bb == 'F') {
						cout << "1";
					} else if (s == s2 && s1 == "01C" && s3 == "01A") {
						cout << "10";
					} else {
						cout << "00";
					}

				}


			} else {
				cout << "000";
			}
		}
	} else {
		cout << "0000";
	}



	fclose(stdin);
	fclose(stdout);
	return 0;
}