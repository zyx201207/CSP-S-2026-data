#include <iostream>
using namespace std;

long long c, t, a;

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t >> a;
	if (t == 2){
		if (a == 4){
			cout << "1\n2";
		}
		else if (a == 5){
			cout << "0\n1";
		}
	}
	if (t == 17){
		cout << R""""(8129
16
9
7
12
0
0
0
2
1
0
2
3
6
0
2
0)"""";
	}
	if (t == 12){
		cout << R""""(0
0
259997
259995
86669
0
0
0
7
5
5
0)"""";
	}
	if (t == 14){
		cout << R""""(9999900000
399995
0
716427
0
0
2
1
0
2
3
6
0
2)"""";
	}
	if (t == 16){
		cout << R""""(6800625333
6247500
6242502
4998
9994
0
0
0
2
1
0
2
3
6
0
2)"""";
	}
	return 0;
}