#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;

struct {
	int cot;
} station[N];

struct {
	int time[N];
} line[510];
bool sr[N][510];
int plan=0,mn[N];
int c, n, m, d, q;
void bfs(int start,int end,int t){
	for(int i=1;i<=n;i++){
		if(sr[start][i]){
			
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> station[i].cot;
	}
	for (int i = 1; i <= n; i++) {
		int sum;
		cin >> sum;
		for (int j = 1; j <= sum; j++) {
			int sm;
			cin >> sm;
			cin >> line[i].time[sm];
			sr[sm][i] = true;
		}
	}
	for (int i = 1; i <= q; i++) {
		int start, end;
		cin >> start, end;
		bfs(start,end,station[start].cot);
		
	}
}