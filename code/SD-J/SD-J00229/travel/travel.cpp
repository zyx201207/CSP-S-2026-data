#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int id1 = (s1[0] - '0') * 10 + s1[1] - '0', 
		id2 = (s2[0] - '0') * 10 + s2[1] - '0';
		
	bool f1, f2, f3;
	f1 = c1 == c2;
	printf("%d", (int)(f1));
	
	f2 = id1 == id2 && f1;
	printf("%d", (int)(f2 && f1));
	
	int line1 = s1[2] - 'A' + 1,
		line2 = s2[2] - 'A' + 1;
		
	f3 = ((line1 <= 3 && line2 <=3) || (line1 > 3 && line2 > 3)) && f2;
	
	printf("%d", (int)(f3));
	
	printf("%d", (int)(abs(line1 - line2) == 1 && f3) );
	
	return 0;
}
