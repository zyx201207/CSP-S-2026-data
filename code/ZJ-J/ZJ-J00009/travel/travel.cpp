#include <bits/stdc++.h>
using namespace std;

const int N = 10;

char c1[N], s1[N], c2[N], s2[N];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%s%s%s%s", c1+1, s1+1, c2+1, s2+1);
	if (c1[1] == c2[1] && c1[2] == c2[2]) {
		putchar('1');
		if (s1[1] == s2[1] && s1[2] == s2[2]) {
			putchar('1');
			bool f1, f2;
			char ch1 = s1[3], ch2 = s2[3];
			f1 = (ch1 == 'A' || ch1 == 'B' || ch1 == 'C');
			f2 = (ch2 == 'A' || ch2 == 'B' || ch2 == 'C');
			if (f1 == f2) {
				putchar('1');
				if (ch1 > ch2)
					swap(ch1, ch2);
				if ((ch1 == 'A' && ch2 == 'B') || (ch1 == 'B' && ch2 == 'C') || (ch1 == 'D' && ch2 == 'F')) {
					puts("1");
				} else {
					puts("0");
				}
			} else {
				puts("00");
			}
		} else {
			puts("000");
		}
	} else {
		puts("0000");
	}
}