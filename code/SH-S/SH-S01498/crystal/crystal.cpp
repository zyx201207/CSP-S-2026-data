#include <bits/stdc++.h>
using namespace std;

struct node{
	int num, cnt;
};

int n;
long long m;
long long ans = 1;
int a[600005];
vector<node> proc;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	node temp = {a[1], 1};
	for (int i = 2; i <= n; i++) {
		if (a[i] == temp.num) {
			temp.cnt++;
			continue;
		}
		else {
			proc.push_back(temp);
			temp.num = a[i];
			temp.cnt = 1;
		}
	}
	proc.push_back(temp);
//	for (int i = 0; i < proc.size(); i++) {
//		cout << proc[i].num << ' ' << proc[i].cnt << endl;
//	}
	for (int i = 1; i < proc.size(); i++) {
		int point = m;
		long long add = proc[i].cnt;
		int standard = proc[i].num;
		for (int j = i - 1; j >= 0; j--) {
			int mxadd = point / abs(proc[j].num - standard);
			if (mxadd >= proc[j].cnt) {
				point -= proc[j].cnt * abs(proc[j].num - standard);
				add += proc[j].cnt;
			}
			else {
				add += mxadd;
				point -= abs(proc[j].num - standard) * mxadd;
				break;
			}
		}
		ans = max(ans, add);
	}
	cout << ans;
}
