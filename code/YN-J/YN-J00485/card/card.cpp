#include <iostream>
using namespace std;
int n;
int a[1001];
int b;

int main() {
	cin >> n >> b;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cout << n << " " << a[1] << " " << b;
		break;
	}
	return 0;
}