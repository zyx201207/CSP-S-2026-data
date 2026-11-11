#include <bits/stdc++.h>

using namespace std;

const char D[3][2] = {{'A', 'B'}, {'C', 'B'}, {'D', 'F'}};
string c1, c2, s1, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c1 >> c2 >> s1 >> s2;
	if (c1 != s1)
		cout << "0000\n";
	else {
		int ic2 = (s1[0] - '0') * 10 + c2[1] - '0';
		int is2 = (s2[0] - '0') * 10 + s2[1] - '0';
		if (ic2 != is2)
			cout << "1000\n";
		else {
			bool ok = 1;
			for (int i = 0; i < 2 && ok; i++)
				if ((c2[2] == D[i][0] && s2[2] == D[i][1]) || (c2[2] == D[i][1] && s2[2] == D[i][0]))
					ok = 0;
			if (ok)
				if ((c2[2] == 'C' && s2[2] == 'A') || c2[2] == 'A' && s2[2] == 'C'){
					cout << "1110\n";
				}
				else
					cout << "1100\n";
			else
				cout << "1111\n";
		}
	}		 
}
