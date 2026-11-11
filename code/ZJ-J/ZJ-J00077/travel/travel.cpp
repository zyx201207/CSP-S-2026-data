#include <iostream>
using namespace std;
int c1, c2, l1, l2, flag1, flag2;
string s1, s2;
char id1, id2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
		cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	for(int i = 0; i <= 1; ++i)
		l1 *= 10, l2 *= 10,
		l1 += ( s1[i] - '0' ),
		l2 += ( s2[i] - '0' );
	if(l1 == l2)
		cout << 1;
	else {
		cout << "000";
		return 0;
	}
	id1 = s1[2], id2 = s2[2];
	flag1 = (id1 == 'A' || id1 == 'B' || id1 == 'C');
	flag2 = (id2 == 'A' || id2 == 'B' || id2 == 'C');
	if(flag1 == flag2)
		cout << 1;
	else {
		cout << "00";
		return 0;
	}
	if(id1 < id2) swap(id1, id2);
	if(flag1 && id1 - id2 == 1)
		cout << 1;
	else if(!flag1 && id1 - id2 == 2)
		cout << 1;
	else cout << 0;
	return 0;
}
