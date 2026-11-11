#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<int> time;

	for (int i = 0; i < m; i++) {

		int t;
		cin >> t;
		time.push_back(t);
	}

//	for(int i=0;i<n;i++){
//		int ki;
//		cin >> ki
//
//	}
	int a = 0;

	for (int i = 0; i < time.size(); i++) {

		a += time[i];
	}

	for (int i = 0; i < q; i++) {

		cout << a << endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}