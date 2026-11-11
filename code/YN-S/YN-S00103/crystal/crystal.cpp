#include <iostream>


using namespace std;

int main() {

	int d = 0, num = 0;
	cin >> d >> num;
	int f[num];
	for ( int i = 0 ; i < num ; i++) {
		cin >> f[i];
	}
	int bf[num - 1];
	int s = 0;
	for (; s < num - 1 ; s ++ ) {
		bf[s] = f[s + 1] - f[ s ];
//		cout << bf[s] << endl;
	}
	int bs[ s / 2 - 1];
	for (int i = 1 ; i < s - 1; i ++) {
		if ( i >= s / 2) {
			for ( int j = s / 2 ; j < s - 1; j ++) {
				bs [ j - 1] = bf [ j ] + bf [ j + 1];
//				cout << " " << bs [ j - 1];
			}
		} else {
			bs [ i - 1] = bf [ i - 1] + bf [ i ];
//			cout << "bs:" << bs [ i - 1];
		}
	}
	for ( int i = 0 ; i <= s / 2 - 1; i++) {
		if (bs[i] + bf[i] == d || bs[i] + bf[i + 1] == d) {
			cout << bs[i];
		}
	}
	return 0;
}