#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, cnt[300005];
vector<int> a, d;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		int c;
		cin >> c;
		a.push_back(c);
	}
	for (int i = 0;i < n;i++) {
		for (int j = i;j < n;j++) {
			vector<int>::iterator it = find(d.begin(), d.end(), a[j]);
			if (it != d.end())
				d.erase(it, d.end());
			d.push_back(a[j]);
		}
		for (int j : d)
			cnt[j]++;
		d.clear();
	}
	for (int i = 1;i <= m;i++)
		cout << cnt[i] << " ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}