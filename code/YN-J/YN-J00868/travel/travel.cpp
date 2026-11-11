#include <bits/stdc++.h>
using namespace std;
char s[10], st[10], l;
int c, ct;

//A 65 B 66 C 67 D 68 F 70 0 48
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d%c%s%d%c%s", &c, &l, s + 1, &ct, &l, st + 1);
	if (c != ct) {
		printf("0000");
	} else {
		printf("1");
		int p = (s[1] - 48) * 10 + (s[2] - 48);
		int pt = (st[1] - 48) * 10 + (st[2] - 48); //ÅÅºÅ×ª»»
		//	printf("p:%d pt:%d\n", p, pt);
		if (p != pt)
			printf("000");
		else {
			printf("1");
			char z = s[3], zt = st[3];
			bool p = 0;
			//	printf("z:%c zt:%c\n", z, zt);
			if (z == 'A' || z == 'B' || z == 'C' && zt == 'A' || zt == 'B' || zt == 'C')
				p = 1;
			if (z == 'D' || z == 'F' && zt == 'D' || zt == 'F')
				p = 1;
			if (p != 1)
				printf("00");
			else {
				printf("1");
				p = 0;
				if (z == 'D' && z == 'F' || zt == 'D' && zt == 'F')
					p = 1;
				if (zt - z == 1 || z - zt == 1)
					p = 1;
				if (z == 'C' && z == 'D' || zt == 'C' && zt == 'D')
					p = 0;
				if (p == 0)
					printf("0");
				else
					printf("1");
			}
		}
	}
	return 0;
}