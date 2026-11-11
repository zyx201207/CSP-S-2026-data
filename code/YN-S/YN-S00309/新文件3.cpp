#include <iostream>
using namespace std;

int main() {
	int n, d;
	cin >> n >> d;
	for (int i; i >= d; i++) {
		cout << i << d;
		if (i > 2 * d) {
			cout << i *i;
		}
	}




	return 0;
}