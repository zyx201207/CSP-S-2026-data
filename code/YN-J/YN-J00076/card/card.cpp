#include <iostream>
#include <string>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, i, sum = 0;
	int *p;
	cin >> n >> m;
	enld;
	int cd[n], cs;
	cin >> cd;
	for (i = 1, i <= n, i++) {
		*p = cd[i];
		for (int v = 1, v <= n, v++) {
			if (cd[0] != *P)
				*p = cd[v + 1];
			else {
				*P = cd[v + 1];
				if (v + 1 = n && *P = i)
					sum += 1;
				else



				}

		}
	};
	fclose(stdin);
	fclose(stdout);
	return 0;
}