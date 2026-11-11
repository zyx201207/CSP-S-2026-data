#include<bits/stdc++.h>
using namespace std;
char c1[10], s1[10], c2[10], s2[10];
bool t1, t2, t3, t4;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%s", c1 + 1);
	scanf("%s", s1 + 1);
	scanf("%s", c2 + 1);
	scanf("%s", s2 + 1);
	t1 = (c1[1] == c2[1] && c1[2] == c2[2]);
	t2 = t1 && (s1[1] == s2[1] && s1[2] == s2[2]);
	int a1 = s1[3], a2 = s2[3];
	t3 = t2 && (a1 < 68 && a2 < 68 || a1 > 67 && a2 > 67);
	t4 = t2 && (abs(a1 - a2) == 1 && !(a1 == 'C' && a2 == 'D'));
	printf("%d%d%d%d\n", t1, t2, t3, t4);
	return 0;
}
