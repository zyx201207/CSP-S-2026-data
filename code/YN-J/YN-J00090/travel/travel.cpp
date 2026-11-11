#include <bits/stdc++.h>
using namespace std;
const int N = 10;
char a[N], b[N], c[N], d[N];
int ans[N];

bool check1(char x, char y) {
	return (x <= 'C' && y <= 'C') || (x > 'C' && y > 'C');
}

bool check2(char x, char y) {
	if (x > y)
		swap(x, y);
	if (x + 1 == y)
		return true;
	if (x == 'D' && y == 'F')
		return true;
	return false;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%s %s ", a + 1, b + 1);
	scanf("%s %s", c + 1, d + 1);
	if (a[1] == c[1] && a[2] == c[2])
		ans[1] = 1;
	else
		ans[1] = 0;
	if (ans[1] == 1 && b[1] == d[1] && b[2] == d[2])
		ans[2] = 1;
	else
		ans[2] = 0;
	if (ans[2] == 1 && check1(b[3], d[3]))
		ans[3] = 1;
	else
		ans[3] = 0;
	if (ans[3] == 1 && check2(b[3], d[3]))
		ans[4] = 1;
	else
		ans[4] = 0;
	printf("%d%d%d%d\n", ans[1], ans[2], ans[3], ans[4]);
	return 0;
}