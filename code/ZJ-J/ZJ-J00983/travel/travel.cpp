#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 10;

string c1, s1, c2, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2)
		printf("0000");
	else {
		printf("1");
		string a, b;
		a = s1[0] + s1[1];
		b = s2[0] + s2[1];
		if (a != b)
			printf("000");
		else {
			printf("1");
			if ((s1[2]>='A' && s1[2]<='c' && s2[2]>='D' && s2[2]<='F') ||
				(s1[2]>='D' && s1[2]<='F' && s2[2]>='A' && s2[2]<='C'))
				printf("00");
			else {
				printf("1");
				if (abs(s1[2] - s2[2]) != 1)
					printf("0");
				else
					printf("1");
			}
		}
	}
	return 0;
}
