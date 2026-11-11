#include <iostream>
using namespace std;

int main() {
	//	freopen("string.in","r",stdin);
//	freopen("string.our","w",stdout);
	int n, m, b;
	cin >> n >> m >> b;
	if (n >= m || m != 0) {
		cout << 2;
	} else {
		cout << 1;
	}
	return 0;
}
