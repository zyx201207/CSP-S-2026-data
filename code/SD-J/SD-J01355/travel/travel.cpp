#include <bits/stdc++.h>
using namespace std;

string a, b, c, d;

int cal(char a) {
	if (a == 'A') return 1;
	if (a == 'B') return 2;
	if (a == 'C') return 3;
	if (a == 'D') return 4;
	if (a == 'F') return 5;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	if (a == c) {
		cout << "1";
		if (b[0] == d[0] && b[1] == d[1]) {
			cout << "1";
			int e = cal(b[2]), f = cal(d[2]);
			if ((e <= 3) == (f <= 3)) {
				cout << "1";
				if (abs(e - f) == 1) cout << "1";
				else cout << "0";
			} else cout << "00";
		} else cout << "000";
	} else cout << "0000";
	return 0;
}
/*
02 01A 02 01B 
*/

/*
几载风雪卷刃 朔风同孤昼
瞧得乱世一般嶙峋瘦
塞外硝烟未断 黄云遍地愁
侥幸红梅久不曾下枝头

天命情况 应似孤鸿游
向人世间尽一副鬼谋
纵意而歌 玉怀斟北斗
河山万里愿与君同守

我自关山点酒 千秋皆入喉
更有飞雪酌与风云某
我是千里古人 青山应白首
年少尤借银枪呈风流 
*/
