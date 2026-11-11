#include <bits/stdc++.h>

using namespace std;

long long n, cnt = 1, x[500010], m, xx, la, lb, ii, jj, ccc;
vector<long long> a;
vector<long long> b;

bool cmp(long long x, long long y)
{
	return x > y;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		scanf("%lld", &x[i]);
	}
	sort(x + 1, x + n + 1);
	ccc = ceil(n / 2.0);
	xx = x[ccc];
	for (int i = 1; i <= n; i ++) {
		if (x[i] > xx) a.push_back(x[i]);
		else if (x[i] < xx) b.push_back(x[i]);
		else cnt ++;
	}
	cnt --;
	
	//cout << a[1];
	//cout << b[1];
	//for (int i = 1; i <= n; i ++) cout << x[i];
	sort(b.begin(), b.end(), cmp);
	la = a.size(), lb = b.size();
	/*for (int i = 0; i < la; i ++) cout << a[i] << endl;
	for (int i = 0; i < lb; i ++) cout << b[i] << endl;*/
	ii = 0, jj = 0;
	//cout << xx;
		while (ii < la && jj < lb) {
			if (xx - b[jj] > m && (a[ii] - xx) * cnt > m) {
				//cout << "aaa"<< ii << jj << " ";
				cout << cnt << endl;
				return 0;
			}
			if (xx - b[jj] <= (a[ii] - xx) * cnt) {
				cnt ++;
				//cout << "b" << b[jj] << endl;
				m -= xx - b[jj];
				jj ++;
			} else {
				//cout << "a" << a[ii] << endl;
				m -= (a[ii] - xx) * cnt;
				xx = a[ii];
				cnt ++;
				ii ++;
			}
		}
	if (ii < la - 1) {
		while ((a[ii] - xx) * cnt < m) {
			m -= (a[ii] - xx) * cnt;
			xx = a[ii];
			cnt ++;
		}
	}
	if (jj < lb - 1) {
		while (xx - b[jj] < m) {
			cnt ++;
			m -= xx - b[jj];
		}
	}
	cout << cnt;
	return 0;
}
