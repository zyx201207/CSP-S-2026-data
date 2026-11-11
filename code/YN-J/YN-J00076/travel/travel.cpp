#include <iostream>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	char c1[3], s1[3], c2[3], s2[3];
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2)
		cout << "1";
	else
		cout << "0";
	if (s1[0] == s2[0] && s1[1] == s2[1])
		cout << "1";
	else
		cout << "0";
	if (s1[2] == 'A', 'B', 'C' && s2[2] == 'A', 'B', 'C') {
		cout << "1";
		if (s1[2] == 'B' || s2[2] == 'B')
			cout << "1";
		else
			cout << "0";
	}
	if (s1[2] == 'D', 'F' && s2[2] == 'D', 'F')
		cout << "1";
	else
		cout << "0";
	fclose(stdin);
	fclose(stdout);
	return 0;
}