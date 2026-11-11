#include<bits/stdc++.h>
using namespace std;
int A,B,C,D;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> a >> b >> c >> d;
	if(b[2] == 'F') b[2] = 'E';
	if(d[2] == 'F') d[2] = 'E';
	if(a == c) A = 1;
	if(b[0] == d[0]&&b[1] == d[1]) B = A&&1;
	if(b[2] >= 'A'&&b[2] <= 'C'&&d[2] >= 'A'&&d[2] <= 'C'||b[2] >= 'D'&&b[2] <= 'E'&&d[2] >= 'D'&&d[2] <= 'E') C = A&&B&&1;
	if(abs(b[2] - d[2]) == 1&&max(b[2],d[2]) != 'D') D = A&&B&&1;
	cout << A << B << C << D;
	return 0;
}
/*
02 02B 02 01A

1000

02 01A 02 01B

1111

02 01C 02 01A

1110

02 01C 02 01D

1100

02 01A 03 01A

0000
*/
