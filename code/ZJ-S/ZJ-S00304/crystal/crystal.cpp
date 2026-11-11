#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500010;
int n, ret;
ll m, a[N], s[N];
int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	scanf ("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf ("%lld", &a[i]);
	}
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		int l = 0, r = i - 1, ans = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (a[i] * (i - mid) - s[i] + s[mid] <= m) {
				ans = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		ret = max (ret, i - ans);
	}
	printf ("%d\n", ret);
	return 0;
}
// 我常常追忆过去。
// 生命瞬间定格在脑海。我将背后的时间裁剪、折叠、蜷曲，揉捻成天上朵朵白云。
// 云朵之间亦有分别：积云厚重，而卷云飘渺。生命里震撼的场景掠过我的思绪便一生无法忘怀，而更为普通平常的记忆在岁月的冲刷下只留下些许残骸。追忆宛如入梦，太过清楚就无法愉悦自己的幻想，过分模糊却又坠入虚无，唯有薄雾间的山水，面纱下的女子，那恰到好处的朦胧，才能满足我对美的苛求。
// 追忆总在不经意间将我裹进泛黄的纸页里。分别又重聚的朋友，推倒又重建的街道，种种线索指引着我从一个具体的时刻出发沿时间的河逆流而上。曾经的日子无法重来，我只不过是一个过客。但我仍然渴望在每一次追忆之旅中留下闲暇时间，在一个场景前驻足，在岁月的朦胧里瞭望过去的自己。美好的时光曾流过我的身体，我便心满意足。
// 过去已经凝固，我带着回忆向前。只是时常疏于保管，回忆也在改变着各自的形态，这给我的追忆旅程带来些许挑战。
// 我该在哪里停留？我问我自己。

// 如果背错勿喷