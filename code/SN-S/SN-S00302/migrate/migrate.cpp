#include <iostream>
#include <vector>
using namespace std;

void migrate(unsigned int d, vector<long long> arr) {
	vector<long long> cost(arr.size() - 1);
	for (int i = 0; i < arr.size()-2; i++) cost[i] = arr[i+1] - arr[i];
	unsigned int n = 1;
	while (cost[n-1] <= d) n++;
	if (n < 3) {
		cout << 0 << endl;
		n = 0;
		return;
	}
	
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out" , "w", stdout);
	unsigned int c, t;
	cin >> c >> t;
	for (int i = 0; i < t; i++) {
		unsigned int n, d;
		cin >> n >> d;
		vector<long long> arr(n);
		for (int j = 0; j < n; j++) cin >> arr[j];
		migrate(d, arr);
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
