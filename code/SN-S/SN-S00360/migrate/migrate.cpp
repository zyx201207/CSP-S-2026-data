// 张睿航 SN-S00360 西安市第六中学 
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int zhc, zht;
int zhn, zhd;
int zhx[100005];
vector<int> zhe[100005];
int zhdis[100005];
int zhcnt[100005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> zhc >> zht;
	while(zht --) {
		cin >> zhn >> zhd;
		for(int i = 1; i <= zhn; i ++) {
			cin >> zhx[i];
		}
		for(int i = 1; i <= zhn; i ++) {
			for(int j = i + 1; j <= zhn; j ++) {
				if(zhx[j] - zhx[i] <= zhd) {
					zhe[i].push_back(j);
					zhe[j].push_back(i);
				}
			}
		}
		memset(zhdis, 0, sizeof(zhdis));
		memset(zhcnt, 0, sizeof(zhcnt));
		int ans = 0;
		for(int i = 1; i <= zhn; i ++) {
			queue<int> q;
			q.push(i);
			while(q.size()) {
				int u = q.front();
				q.pop();
				for(int v : zhe[u]) {
					if(zhdis[v] == 0 && v != i) {
						zhdis[v] = zhdis[u] + 1;
						q.push(v);
						zhcnt[v] = 0;
					}
					if(zhdis[v] == zhdis[u] + 1) {
						zhcnt[v] ++;
					}
				}
			}
			for(int j = 1; j <= zhn; j ++) {
				if(zhcnt[j] == 2) ans ++;
			}
		}
		ans /= 2;
		cout << ans << '\n';
	}
	return 0;
}
