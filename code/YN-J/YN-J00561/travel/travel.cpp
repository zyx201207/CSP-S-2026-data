#include <cstdio>
#include <iostream>
using namespace std;

int main (void) {
	//freopen("travel.in", "r", stdin);
	//freopen("travel.out", "w", stdout);
	int r[256] = {0};
	char a[256] = {0}, b[256] = {0}, c[256] = {0}, d[256] = {0};
	for (int i = 0; i < 2; i++) {
		scanf("%c", &a[i]);
	}
	for (int i = 0; i < 3; i++) {
		scanf("%c", &b[i]);
	}
	for (int i = 0; i < 2; i++) {
		scanf("%c", &c[i]);
	}
	for (int i = 0; i < 3; i++) {
		scanf("%c", &d[i]);
	}
	for (int i = 0; i < 2; i++) {
		if (a[i] == c[i]) {
			r[0] = 1;
		}
		if (b[i] == d[i]) {
			r[1] = 1;
		}
	}
	if (b[2] <= 'C' && d[2] <= 'C') {
		r[2] = 1;
	}
	if (b[2] + 1 == c[2] || b[2] - 1 == c[2]) {
		r[3] = 1;
	}
	for (int i = 0; i < 4; i++) {
		printf("%d ", r[i]);
	}
	return 0;
	//fclose(stdin);
	//fclose(stdout);
}