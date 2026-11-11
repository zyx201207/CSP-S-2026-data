#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	unsigned int n;
	long long m;
	cin >> n >> m;
	vector<int> arr(n);
	for (unsigned int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	
	unsigned int x = 1;
	long long y;
	for (unsigned int i = 0; i < n - 1; i++) {
		if (arr[i] == arr[i+1]) x++;
		if (arr[i] < arr[i+1]) {
			m -= (arr[i+1] - arr[i]) * x;
			x = i;
			if (m < 0) break;
			y = arr[i+1];
			if (m <= 0) {
				for (unsigned int j = i + 2; j < n - 1; j++) {
					if (arr[j] == y) {
						x = j;
						continue;
					}
					break;
				}
				break;
			}
		}
	}
	
	cout << x + 1 << endl;
	
	return 0;
}
