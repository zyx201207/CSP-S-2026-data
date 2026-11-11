#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int cx, sx, cy, sy;
char x, y;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1;
	for (int i = 0; i < c1.size(); i++) cx = cx * 10 + c1[i] - '0';
	cin >> s1;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] >= '0' && s1[i] <= '9') sx = sx * 10 + s1[i] - '0';
		else x = s1[i];
	}
	cin >> c2;
	for (int i = 0; i < c2.size(); i++) cy = cy * 10 + c2[i] - '0';
	cin >> s2;
	for (int i = 0; i < s2.size(); i++) {
		if (s2[i] >= '0' && s2[i] <= '9') sy = sy * 10 + s2[i] - '0';
		else y = s2[i];
	}
	cout << (cx == cy);
	cout << (cx == cy && sx == sy);
	cout << (cx == cy && sx == sy && ((x <= 'C' && y <= 'C') || (x >= 'D' && x <= 'F' && y >= 'D' && y <= 'F')));
	cout << (cx == cy && sx == sy && ((x <= 'C' && y <= 'C') || (x >= 'D' && x <= 'F' && y >= 'D' && y <= 'F')) && abs((int)x - (int)y) == 1);
	return 0;
} 
