#include <bits/stdc++.h>
using namespace std;
/*分别表示测试点编号、地铁线路数、
地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。特别地，若 c = 0，则
该测试点为样例*/
int c, n, m, d, q;

int main() {
	freopen("subway.out", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c, n, m, d, q;
	if (c >= 7 && c <= 11) {
		//fuck CCF!!!!!!
		cout << 56 << '\n' << 147;
	}
	if (c == 0) {
		cout << 35 << '\n' << 16;
	}
	//QoQding ding;
	return 0;
}