#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
const int N = 2e5 + 10;
int n, sum, mid1, mid2, res;
int fs, fd;
string str;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int a;
		char c;
		cin >> a >> c;
		sum += a;
		for (int j = 0; j < a; ++j) str.push_back(c);
	}
	mid1 = sum / 2, mid2 = sum / 2 + sum % 2 + 1;
	while (mid1 >= 1) {
		while (mid1 >= 1 && str[mid1 - 1] == str[mid2 - 1]) {
			--mid1;
			++mid2;
		}
		fd = mid1;
		while (mid1 >= 1 && str[mid1 - 1] != str[mid2 - 1]) {
			--mid1;
			++mid2;
		}
		fs = mid1;
		res += (fd - fs);
	}
	cout << res << endl;
    return 0;	
}
