#include<bits/stdc++.h>
using namespace std;
bool fa, fb, fc, fd;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int ax, bx;
	string ay, by;
	cin >> ax >> ay >> bx >> by;
	if(ax == bx) {
		fa = 1;
	}
	int a = (ay[0] - '0') * 10 + (ay[1] - '0');
	int b = (by[0] - '0') * 10 + (by[1] - '0');
	if(fa == 1 && a == b) {
		fb = 1;
	}
	if(fb == 1 && ((((ay[2] >= 'A') && (ay[2] <= 'C')) && ((by[2] >= 'A') && (by[2] <= 'C'))) || (((ay[2] >= 'D') && (ay[2] <= 'E')) && ((by[2] >= 'D') && (by[2] <= 'E'))))) {
		fc = 1;
	}
	if(fc == 1 && (((ay[2] -'0') - (by[2] -'0') == 1) || ((by[2] -'0') - (ay[2] -'0') == 1))) {
		fd = 1;
	}
	cout << fa << fb << fc << fd;
	return 0;
}
