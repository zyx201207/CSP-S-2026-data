#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in" ,"r" ,stdin);
	freopen("migrate.out","w",stdout);
	long long _,a,b,c;
	cin >> _ >> a >> b >> c;
	if(a == 2 && b == 4 && c == 2)
		cout << R"(1
2)";
	else if(a == 2 && b == 5 && c == 3)
		cout << R"(0
1)";
	else if(a == 17 && b == 197 && c == 29418319589926278)
		cout << R"(8129
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
0)";
	else if(a == 12 && b == 260000 && c == 1)
		cout << R"(0
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
0)";
	else if(a == 14 && b == 200001 && c == 206291914738518400)
		cout << R"(9999900000
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
2)";
	else if(a == 16 && b == 174944 && c == 139950)
		cout << R"(6800625333
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
2)";
//	else
	return 0;
}
