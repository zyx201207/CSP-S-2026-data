#include <bits/stdc++.h>
using namespace std;
int ccc = 0;
string q(int n) {
	string a = "0000000000000000000000000000000";
	int s = 30;
	while(n >= 1) {
		char t = (n % 2) + '0';
		a[s] = t;
		s--;
		n /= 2;
	}
	return a;
}
int t(string a) {
	int n = 0, b = 1;
	for (int i = 30; i >= 0; i--) {
		char e = a[i];
		
		n += (int)(e - '0') * b;
		b *= 2;
	}
	return n;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n];
	string b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = q(a[i]);
	}
	vector<int> o(1000005);
	for (int i = 31; i >= 0; i--) {
		if (ccc != 0) {
			vector<int> g;
			for (int j = 0; j < (int)ccc; j++) {
				string ddd = b[o[j]];
				if (ddd[i] == '1') {
					g.push_back(o[j]);
				}//xshai,
			}
			if ((int)g.size() < m) {
				ccc = 0;
				continue;
			} else if ((int)g.size() == m) {
				for (int j = 0; j < (int)g.size(); j++) {
					o[i] = g[i];
				}
				ccc = m;
				break;
			} else {
				ccc = g.size();
				for (int j = 0; j < (int)g.size(); j++) {
					o[i] = g[i];
				}
			}
		} else {
			ccc = 0;
			for (int j = 0; j < n; j++) {
				if (b[j][i] == '1') {
					o[ccc] = j;
					ccc++;
				}
			}
			if (ccc < m) {
				ccc = 0;
				continue;
			}
			if (ccc == m) {
				break;
			}
		}
		
	}
	if (ccc == 0) {
		cout << 0 << endl;
		return 0;
	}
	/**/
	/**/
	int y = 2147483647;
	for (int i = 0; i < ccc; i++) {
		y = y & t(b[o[i]]);
	}
	cout << y << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
