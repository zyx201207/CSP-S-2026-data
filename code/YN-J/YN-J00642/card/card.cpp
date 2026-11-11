#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	vector<int> tp(m + 2, 0);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < n; i++) {
		vector<int> vdj;
		for (int j = i; j < n; j++) {
			vdj.push_back(v[j]);
		}
		for (int j = 0; j < vdj.size() - 1; j++) {
			for (int x = j + 1; x < vdj.size(); x++) {
				if (vdj[j] == vdj[x]) {
					for (int y = j; y < x; y++)
						vdj[y] = m + 1;
					j = x;
				}
			}
		}
		unique(vdj.begin(), vdj.end());
		int zb = vdj.size();
		for (int j = 0; j < vdj.size() - 1; j++) {
			for (int x = j + 1; x < vdj.size(); x++) {
				if (vdj[j] == vdj[x]) {
					zb = x;
					break;
				}
			}
		}
		for (int j = 0; j < zb; j++) {
			tp[vdj[j]]++;
		}
	}
	for (int i = 1; i < tp.size() - 1; i++) {
		cout << tp[i] << " ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}