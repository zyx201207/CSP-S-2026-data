#include <bits/stdc++.h>
#define int long long
using namespace std;

char c1[100], s1[100], c2[100], s2[100];

signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout); 
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1[0] != c2[0] || c1[1] != c2[1])
		printf("0000");
	else {
		printf("1");
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			printf("1");
			char a = s1[2], b = s2[2];
			if ((a == 'A' && (b == 'B' || b == 'C')) || 
				(a == 'B' && (b == 'A' || b == 'C')) || 
				(a == 'C' && (b == 'A' || b == 'B')) ||
				(a == 'D' && b == 'E')) {
				printf("1");
				if (a == 'A' && b == 'B' || a == 'B' && b == 'C' || a == 'D' && b == 'E')
					printf("1");
				else
					printf("0");
			} else
				printf("00");
		} else
			printf("000");
	}
	return 0;
}
