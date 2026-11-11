#include <iostream>
using namespace std;
int a[100];
char b[100];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n ; i++) {
		cin >> a[i] ;
		cin >> b[i] ;
		if (a[i]*b[i] == b[i]*a[i]) {
			cout << "2";
		}
	}

	return 0;
}