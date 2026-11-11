#include <bits/stdc++.h>
#define N 500005

using namespace std;

int c, n, m, d, q;
int w[N];
long long sum;
int main() {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
		sum += w[i];
	}
	cout << sum << endl << sum / 2;
	return 0;
}
//怎么又又又又又考图
//我想玩florr，我这个蒟蒻怎么怎么做这种难题qwp
//我马上要全究极三角形了！！
//这个题肯定是图，所以我要画一个花园的地图，然后拿花瓣打昆虫
//不不不不不不不不不不
//怎么又有究极蠕虫
//我的合成爆率怎么怎么低
//nonono我有不想玩了
//还是做题吧orz
//-----来自一个初二蒟蒻。。。。