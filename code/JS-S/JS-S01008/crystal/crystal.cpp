/*
能量水晶，又称音乐水晶，是著名音乐游戏曲目 Xterfusion 的 BGA (Background Animation) 中的著名要素之一。
曲目歌词如下：

Xterfusion

3
2
1
go

yeah, come on

Only feels like nothing could be better when I'm with you
When I'm with you
Dancing all night pray we're next together it's a breakthrough
It's a breakthrough

X X XXX
O O OOO
XX X XXX
OO O OOO
X X X XXXX
O O O OOOO
XX XX XXX X X
OO OO OOO O O
X X X
O O O
XXX X
OOO O
XXX XXX
OOO OOO
XXXXX
OOOOO
XXXXXXX
OOOOOOO
XXX X X
OOO O O
XXOOXXOOXXOOXXOO
XOXOXOXOXOXOXOXO
OOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOO

Only feels like nothing could be better when I'm with you
When I'm with you
*/

#include<bits/stdc++.h>
const int N = 5e5 + 5;
typedef long long ll;
ll A[N], sum[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	ll m;
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%lld", A + i);
	std::sort(A + 1, A + 1 + n);
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + A[i];
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int l = 1, r = i, res;
		auto check = [i, m](int mid) {
			ll cost = A[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]);
			return cost <= m;
		};
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(check(mid))
				r = mid - 1, res = mid;
			else
				l = mid + 1;
		}
		ans = std::max(ans, i - res + 1);
	}
	printf("%d\n", ans);
	return 0;
}
