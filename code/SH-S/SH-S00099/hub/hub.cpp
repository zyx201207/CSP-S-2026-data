#include<iostream>
#define int long long
#define gc getchar
#define pc putchar
using namespace std;
int rd() {
	int res = 0, c = gc();
	bool f = false;
	while (c < 48 || c > 57) {
		if (c == 45) f = true;
		c = gc();
	}
	while (48 <= c && c <= 57) res = (res << 3) + (res << 1) + (c ^ 48), c = gc();
	if (f) return -res;
	return res;
}
void wr(int x) {
	if (x > 9) wr(x / 10);
	pc(x % 10 + 48);
}
signed main() {
}
