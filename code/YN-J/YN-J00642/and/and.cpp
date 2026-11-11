#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Jz(vector<int> &v) {
	vector<vector<int>> vres;
	for (int i = 0; i < v.size(); i++) {
		vector<int> nv;
		while (v[i] > 0) {
			nv.push_back(v[i] % 2);
			v[i] /= 2;
		}
		reverse(nv.begin(), nv.end());
		vres.push_back(nv);
	}
	return vres;
}

vector<int> Awy(vector<int> a, vector<int> b) {
	int as = a.size(), bs = b.size();
	int cs = min(as, bs);
	vector<int> c(cs, 0);
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for (int i = 0; i < cs; i++) {
		if (a[i] == b[i] && a[i] == 1)
			c[cs - i - 1] = 1;
		else
			c[cs - i - 1] = 0;
	}
	bool flag = 0;
	for (int i = 0; i < c.size(); i++) {
		if (c[i] != 0)
			flag = 1;
	}
	if (flag == 1)
		return c;
}

vector<int> Yres(vector<vector<int>> &vres) {
	vector<int> ans;
	for (int i = 0; i < vres.size(); i++) {
		int powb = 0;
		int answ = 0;
		for (int j = vres[i].size() - 1; j >= 0; j--) {
			if (vres[i][j])
				answ += pow(2, powb);
			powb++;
		}
		ans.push_back(answ);
	}
	return ans;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int cs = m - 1;
	if (cs == 0) {
		int na = INT_MIN;
		for (int i = 0; i < n; i++)
			na = max(na, v[i]);
		cout << na;
		return 0;
	}
	vector<vector<int>> vres = Jz(v);
	while (cs--) {
		vector<vector<int>> vres2;
		for (int i = 0; i < vres.size() - 1; i++) {
			for (int j = i + 1; j < vres.size(); j++) {
				vres2.push_back(Awy(vres[i], vres[j]));
			}
		}
		vres = vres2;
	}
	vector<int> ans = Yres(vres);
	int maxn = INT_MIN;
	for (int i = 0; i < ans.size(); i++) {
		maxn = max(maxn, ans[i]);
	}
	cout << maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}