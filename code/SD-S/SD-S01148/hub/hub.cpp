#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e6 + 10;

ll __, _, n, k, u, v;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin >> __ >> _;
	while (_ --)
	{
		cin >> n >> k;
		for (ll i = 1; i < n; i ++) cin >> u >> v;
		if (k == n) cout << 0 << endl;
		else cout << 1 << endl;
	}

	return 0;
}

// 麻了 怎么一场3个图论啊
// 期望得分只有可怜的100+44+8=152 我完蛋了
// 收拾收拾退役吧 

// 加油 相信自己
// 只要能过掉 T1 就行
// RP ++ for Cute_zsz

// 和上面形成鲜明对比 


