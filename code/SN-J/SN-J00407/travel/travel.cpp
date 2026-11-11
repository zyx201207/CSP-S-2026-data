#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char c1[10], c2[10], s1[10], s2[10];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%c%c %c%c%c %c%c %c%c%c", &c1[1], &c1[2], &c2[1], &c2[2], &c2[3], &s1[1], &s1[2], &s2[1], &s2[2], &s2[3]);
	if (c1[1] != s1[1] || c1[2] != s1[2]) puts("0000");
	else if (c2[1] != s2[1] || c2[2] != s2[2]) puts("1000");
	else if ((c2[3] <= 'C' && s2[3] >= 'D') || (s2[3] <= 'C' && c2[3] >= 'D')) puts("1100");
	else if (abs(c2[3] - s2[3]) > 1) puts("1110");
	else puts("1111");
}
