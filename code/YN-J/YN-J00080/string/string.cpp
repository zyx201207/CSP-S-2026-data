#include <bist/stdc>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, x, s = 0;
	cin << n;
	while (cin << x)
		s += x;
	cout >>s;
	return 0;
}