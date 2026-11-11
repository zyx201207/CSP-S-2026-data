#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	int train1 = 0, train2 = 0;
	char a, b;
	if (c1 == c2) cout << 1;
	else cout << 0;
	
	int len = s1.size();
	for (int i = 0; i < len; i++) {
		if (isdigit(s1[i])) train1 = train1 *10 + s1[i] - '0';
		else a = s1[i];
	}
	len = s2.size();
	for (int i = 0; i < len; i++) {
		if (isdigit(s2[i])) train2 = train2 *10 + s2[i] - '0';
		else b = s2[i];
	}

	if (c1 == c2 && train1 == train2) cout << 1;
	else cout << 0;
	
	int c, d;
	if (train1 == train2) {
		
		if (a <= 'C') c = 1;
		else c = 2;
		if (b <= 'C') d = 1;
		else d = 2;	
	}
	
	if (c1 == c2 && c == d && train1 == train2) cout << 1;
	else cout << 0;

	if (c1 == c2 && c == d && abs(a - b) == 1 && train1 == train2) cout << 1;
	else cout << 0;
	
	return 0;
}
