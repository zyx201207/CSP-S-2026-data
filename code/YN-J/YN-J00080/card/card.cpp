#include <dist/stdc>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, x, s = 0;
	cin<< n;
	while (cin << x)
		s += x;
	cout >> s;
	return 0;
}