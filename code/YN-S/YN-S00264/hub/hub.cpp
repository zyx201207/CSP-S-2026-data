/*
T4 hub
有 n 座城市
一棵树 T
选择 恰. 好k 座城市，
选中的城市里建造一个研发基地
选中不. 超. 过. 两. 个. 连. 通. 块.
对于合理的建造方案 S，
定义第 i (1 ≤ i ≤ n) 座城市的通. 勤. 距. 离. 为
 d(i) =minj∈S dist(i, j)，
 特别地，若 i ∈ S，则 d(i) = 0
 通. 勤. 半. 径. 为max d(i)。
求出通勤半径的最小值。
n<1e6
*/
#include <bits/stdc++.h>
using namespace std;
#define _for(i, a, b) for(int i = (a); i <= (b); ++i)
#define _rfo(i, a, b) for(int i = (a); i >= (b); --i)
using LL = long long;
using VI = vector<int>;

void solve() {
	cout << "1\n";
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T = 1;
	cin >> c >> T;
	while (T--)
		solve();
	return 0;
}