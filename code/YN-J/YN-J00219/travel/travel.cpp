#include <iostream>
using namespace std;

int lr, lx;
int zwr, zwx;
char rr, xx;

bool p(char a, char b) {
	if ((a == 'D' && b == 'F') || (a == 'F' && b == 'D')) return 1;
	if ((a == 'C' && b == 'D') || (a == 'D' && b == 'C')) return 0;
	if (abs(a - b) == 1) return 1;
	return 0;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d %d%c %d %d%c", &lr, &zwr, &rr, &lx, &zwx, &xx);
	if (lr == lx) printf("1");
	else printf("0");
	if (lr == lx && zwr == zwx) printf("1");
	else printf("0");
	if (lr == lx && zwr == zwx && 
		((rr >= 'A' && rr <= 'C' && xx >= 'A' && xx <= 'C') || 
		(rr >= 'D' && rr <= 'F' && xx >= 'D' && xx <= 'F'))) printf("1");
	else printf("0");
	if (lr == lx && zwr == zwx && p(rr, xx)) printf("1");
	else printf("0");

	return 0;
}
