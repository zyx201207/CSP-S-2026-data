/*

	rating: 800
	good

*/

#include <bits/stdc++.h>

char a[15], b[15], c[15], d[15];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%s%s%s%s", a + 1, b + 1, c + 1, d + 1);
	int car1 = (a[1] - '0') * 10 + a[2] - '0', car2 = (c[1] - '0') * 10 + c[2] - '0';
	int row1 = (b[1] - '0') * 10 + b[2] - '0', row2 = (d[1] - '0') * 10 + d[2] - '0';
	int seat1 = b[3] - 'A', seat2 = d[3] - 'A';
	if (seat1 == 5) {
		seat1 = 4;
	}
	if (seat2 == 5) {
		seat2 = 4;
	}
	if (car1 == car2) {
		printf("1");	
	} else {
		printf("0");
	}
	if (car1 == car2 && row1 == row2) {
		printf("1");
	} else {
		printf("0");
	}
	if (car1 == car2 && row1 == row2 && ((seat1 <= 2 && seat2 <= 2) || (seat1 >= 3 && seat2 >= 3))) {
		printf("1");
	} else {
		printf("0");
	}
	if (car1 == car2 && row1 == row2 && ((seat1 <= 2 && seat2 <= 2) || (seat1 >= 3 && seat2 >= 3)) && abs(seat1 - seat2) == 1) {
		printf("1");
	} else {
		printf("0");
	}
	return 0;
} 
