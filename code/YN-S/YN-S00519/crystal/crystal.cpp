#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	bool pd = 0;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i) {
			pd = 1;
		}
	}
	if (!pd) {
		ll sum = 0;
		for (ll i = 1; i <= m; i++) {
			sum += i;
			if (sum == m) {
				cout << i + 1 << "\n";
				return 0;
			}
			if (sum > m) {
				cout << i << "\n";
				return 0;
			}
		}
	}
	sort(a + 1, a + 1 + n);
	ll ans = 0;
	for (ll i = a[n]; i >= 1; i--) {
		ll pos = upper_bound(a + 1, a + 1 + n, i) - a - 1;
		ll js = 0;
		ll j = pos;
		ll bf = m;
		while (bf > 0 && j >= 1) {
			bf -= (i - a[j]);
			j--;
			if (bf >= 0) {
				js++;
			}
		}
		ans = max(ans, js);
	}
	cout << ans << "\n";
	return 0;
}
//唧唧复唧唧
//木兰当户织
//不闻机杼声
//惟闻女叹息
//问女何所思
//问女何所忆
//女亦无所思
//女亦无所忆
//昨夜见军帖
//可汗大点兵
//军书十二卷
//卷卷有爷名
//阿爷无大儿
//木兰无长兄
//愿为市鞍马
//从此替爷征
//东市买骏马
//西市买鞍鞯
//南市买辔头
//北市买长鞭
//旦辞爷娘去
//暮宿黄河边
//不闻爷娘唤女声
//但闻黄河流水鸣溅溅
//旦辞黄河去
//暮至黑山头
//不闻爷娘唤女声
//但闻燕山胡骑鸣啾啾
//万里赴戎机
//关山度若飞
//朔气传金柝
//寒光照铁衣
//将军百战死
//壮士十年归
//归来见天子
//天子坐明堂
//策勋十二转
//赏赐百千强
//可汗问所欲
//木兰不用尚书郎
//愿驰千里足
//送儿还故乡
//爷娘闻女来
//出郭相扶将
//阿姊闻妹来
//当户理红妆
//小弟闻姊来
//磨刀霍霍向猪羊
//开我东阁门
//坐我西阁床
//脱我战时袍
//著我旧时裳
//当窗理云鬓
//对镜贴花黄
//出门看火伴
//火伴皆惊忙
//同行十二年
//不知木兰是女郎
//雄兔脚扑朔
//雌兔眼迷离
//双兔傍地走
//安能辨我是雄雌