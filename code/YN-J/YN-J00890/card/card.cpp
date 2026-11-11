#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
int a, b, c[500005], dd[300005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> a >> b;
	for (int d = 1; d <= a; d++) {
		cin >> c[d];
	}
	for (int e = 1; e <= a; e++) {
		stack<int> m;
		int n[500005] = {-1} ;
		for (int f = e, ff = 0; f <= a; f++, ff++) {
			if (n[c[f]] == -1) {
				n[c[f]] = ff;
			} else {
				int l = n[c[f]];
				for (int k = l + 1 ; k < ff  ; k++) {
					if (k != l + 1   ) {
						n[m.top()] = -1;
					}
					m.pop();
				}
				ff = l   ;
			}
			m.push(c[f]);
		}
		for (int g = 0; g < m.size(); g++) {
			dd[m.top()]++;
			m.pop();
		}
		cout  << endl;
	}
	for (int h = 1; h <= b; h++) {
		cout << dd[h] << " ";
	}
	return 0;
}