#include <bits/stdc++.h>
using namespace std;
int c1, c2, s1, s2;
int n;

int main() {
	//frozpen("travel","r",stdin)
	//frozpen("travel","w",stdout)
	cin >> c1 >> c2 >> s1 >> s2;
	for (int i = 1; i <= n; i++) {
		if (c1 == c2 == s1 && c1 == c2 == s2) {
			cout << "1111" << endl;
		} else if (c1 == c2 == s2 && c2 == s2) {
			cout << "1110" << endl;
		} else if (c1 == c2 && c2 == s2) {
			cout << "1100" << endl;
		}
	}
	return 0;
}