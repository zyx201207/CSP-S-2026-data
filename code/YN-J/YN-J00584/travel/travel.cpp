#include <bits/stdc++.h>
using namespace std;

bool line(char a, char b) {
	int a1 = 1, b1 = 1;
	if (a == 'A' || a == 'B' || a == 'C') {
		a1 = 0;
	}
	if (b == 'A' || b == 'B' || b == 'C') {
		b1 = 0;
	}
	if (a1 == b1)
		return true;
	else
		return false;
}

bool side(char a, char b) {
	if (a == 'A' && b == 'B')
		return true;
	else if ((a == 'B' && b == 'A') || (a == 'B' && b == 'C'))
		return true;
	else if (a == 'C' && b == 'B')
		return true;
	else if (a == 'D' && b == 'F')
		return true;
	else if (a == 'F' && b == 'D')
		return true;
	else
		return false;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	string s1, c1, s2, c2;
	cin >> s1 >> c1 >> s2 >> c2;
	if (s1 != s2) {
		cout << "0000";
		return 0;
	}
	cout << 1;

	string p1, p2;
	p1 += c1[0] + c1[1];
	p2 += c2[0] + c2[1];
	if (p1 == p2)
		cout << 1;
	else {
		cout << "000";
		return 0;
	}

	char q1 = c1[2], q2 = c2[2];
	if (line(q1, q2)) {
		cout << 1;
	} else {
		cout << "00";
		return 0;
	}

	if (side(q1, q2))
		cout << 1;
	else
		cout << 0;
	return 0;
}

//过了
//应该能拿分了
//OvO  08:52
//还会有人看游记吗？08:57
//为什么有（ int main(void) ）？？？  看来是我孤陋寡闻了 09:05
//#Undertale #Minecraft #War Thunder #Blue Archive, @BVVD,土豆发芽了  09:10
//神秘显示器抽风了，变成蓝色了QAQ 09:22
//欸?它又变回去了。 09:30
//T3蒙出来了 10:04
//我前面那个BRO怎么还在做T1? 10:34
//全国统一评测时采用的机器配置为：Intel Core Ultra 9 285K CPU @ 3.70 Ghz,简称"ICU 9 CPU @ 3.70 Ghouzi(GMonkey)"
//感觉T2 疑似可以暴力PA了？11 : 30
//为什么下午还要考啊。
//燃尽了...11:34
//神秘显示器最后时刻又抽风变成蓝色了QAQ11：58