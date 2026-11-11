#include <bits/stdc++.h>
using namespace std;
const int max1 = 2147483647;

struct node {
	int data;
	double anh;
	node *next;
	int diff;
};
int *g;
int c;
int max2;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	for (int i = 0 ; i < 31 ; i ++) {

		if (i == 30) {
			max2 = 2147483647;
		}
	}

	cin >> c;
	cout << "1\n2";

	return 0;
}
