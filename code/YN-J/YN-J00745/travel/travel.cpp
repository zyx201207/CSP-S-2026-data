#include <iostream>
using namespace std;

int main() {
	freopen("travel.in", "r")std;
	freopen("travel.out", "w")std;
	string cx, sx, cy, sy;
	cin >> cx >> sx >> cy >> sy;
	int cnt = 0;
	if (cx == cy)
		cnt += 1000;

	if (cnt == 0)
		cout << "0000";
	else
		cout << cnt;
	return 0;
}