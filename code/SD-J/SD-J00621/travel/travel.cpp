#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[5], s1[5], c2[5], s2[5];
	for (int i = 1; i <= 2; i++) cin >> c1[i];
	for (int i = 1; i <= 3; i++) cin >> c2[i];
	for (int i = 1; i <= 2; i++) cin >> s1[i];
	for (int i = 1; i <= 3; i++) cin >> s2[i];
	if (c1[1] == s1[1] && c1[2] == s1[2]) {
		cout << "1";
		if (c2[1] == s2[1] && c2[2] == s2[2]) {
			cout << "1";
			if (c2[3] <= 'C' && s2[3] <= 'C' || c2[3] >= 'D' && s2[3] >= 'D') {
				cout << "1";
				if (c2[3] - s2[3] == 1 || c2[3] - s2[3] == -1) {
					cout << "1";
				}
				else cout << "0";
			}
			else cout << "0";
		}
		else cout << "0";
	}
	else cout << "0";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
