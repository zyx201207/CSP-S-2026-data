#include <bits/stdc++.h>
using namespace std;
int a, b;
string x, y;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> x >> b >> y;

	if (a == b) {
		cout << 1;
	} else {
		cout << "0000";
		return 0;
	}

	if (x[0] == y[0] && x[1] == y[1]) {
		cout << 1;
	} else {
		cout << "000";
		return 0;
	}

	if ((x[2] >= 'D' && y[2] >= 'D') || (x[2] <= 'C' && y[2] <= 'C')) {
		cout << 1;
	} else {
		cout << "00";
		return 0;
	}

	if (abs((int)(x[2] - y[2])) == 1) {
		cout << 1;
	} else {
		cout << 0;
	}

	return 0;
}
//删注�?ccf你个死妈的傻�?报名费几把的310+100你也�?今年csp-j你他妈T4敢出DP我就把你妈操到天上去！！！！！！！！！！！！！！！！！！！！
//删注�?ccf你个死妈的傻�?报名费几把的310+100你也�?今年csp-j你他妈T4敢出DP我就把你妈操到天上去！！！！！！！！！！！！！！！！！！！！
//删注�?ccf你个死妈的傻�?报名费几把的310+100你也�?今年csp-j你他妈T4敢出DP我就把你妈操到天上去！！！！！！！！！！！！！！！！！！！！
//删注�?ccf你个死妈的傻�?报名费几把的310+100你也�?今年csp-j你他妈T4敢出DP我就把你妈操到天上去！！！！！！！！！！！！！！！！！！！！
//删注�?ccf你个死妈的傻�?报名费几把的310+100你也�?今年csp-j你他妈T4敢出DP我就把你妈操到天上去！！！！！！！！！！！！！！！！！！！！
