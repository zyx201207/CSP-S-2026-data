#include <bits/stdc++.h>
using namespace std;
int main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m, a[100000], w[100000], maxn = 0, s = 0;
	bool b[100000] = {0};
	cin >> n >> m;
	for (long long i = 0; i < n; i++){
		cin >> a[i];
		int q= a[i];
		b[q] = 1;
		if (maxn < q) maxn = q;
	}
//	cout << maxn << endl;
	for (long long i = 0; i < maxn; i++){
//		cout << b[i] << " " << i << " ";
//看我代码的是gay
// 观沧海 曹操 东临碣石 以观沧海 水何澹澹 山岛悚置 树木丛生 百草丰茂 秋风萧瑟 洪波涌起 日月之行 若出其中 星汉灿烂 若出其里 幸甚至在 歌以咏志
// 闻王昌龄左迁龙标遥有此寄 李白 杨花落尽子规啼 闻道龙标过五溪 我寄愁心与明月 随君直到夜郎西
// 鲁迅先生做宾客而怀橘乎 吾母性之所爱 故归以以母 
		if(b[i] == 1) w[s++] = i;
	}
	long long q;
	s-=1;
	if (s %2==0){
		q=s/2;
	} 
	else {
		q = s/2+1;
	}
	cout << w[q];
	return 0;
}
