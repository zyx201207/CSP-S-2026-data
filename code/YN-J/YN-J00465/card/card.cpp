#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
int qzh[maxn];
bool vis[maxn];
int topp, cnt, loww, n, m;
stack<int> num;
deque<int> inn;
queue<int> q;



int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	int k;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		if (vis[k]) {
			//cout << 1;
			while (inn.front() != k) {
				cout << 1;
				int los = num.top();
				num.pop();
				vis[los] = 0;
				inn.pop_back();
				cnt--;
			}
		} else {
			vis[k] = 1;
			inn.push_back(k);
			cnt++;
			int cnt1 = 0;
			while (cnt1 < cnt) {
				cnt1++;
				int numm = inn.front();
				inn.pop_front();
				inn.push_back(numm);
				if ((!vis[numm + 1] ) && numm + 1 <= n)
					qzh[numm + 1]--;
				qzh[numm]++;
			}

		}
	}
	int gettt = 0;
	for (int i = 1; i <= m; i++) {
		gettt += qzh[i];
		printf("%d ", gettt);
	}




	return 0;
}