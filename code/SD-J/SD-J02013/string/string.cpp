#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
int main() {
	freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
	
	//	*非正解，效率极低 
	//  用循环将输入的字符拼接到一个字符串中，然后双指针暴力枚举不相同的字符。 
	ll n, a;
	string s, c;
	cin >> n;
	while (n--) {
		cin >> a >> c;
		while (a--) s += c;
	}
	ll len = s.length() - 1, ans = 0;
	for (int i = 0, j = len; i < j; i++, j--) {
		if (s[i] != s[j]) ans++;
	}
	cout << ans << '\n';
	return 0;
}

// 处理输入，使用结构体存储，若相邻的字母相同，就累加数字 
//	cin >> n;
//	s[0].c = 'A', s[0].a = 6767;
//	while (n--) {
//		ll ta;
//		char tc;
//		cin >> ta >> tc;
//		if (s[len - 1].c == tc) s[len - 1].a += ta;
//		else {
//			s[len].a = ta;
//			s[len++].c = tc;
//		}
//	}
//	ll ans = 0, dp0, dp1;
//	len--;
//	/*
//	正解？ 
//	双指针遍历所有的结构体，分情况处理： 
//	1. 两个指针指向的字母相同
//	2. 字母不同  
//	*/
//	for (int i = 1, j = len; i < j; ) {
//		ll cha = abs(s[i].a - s[j].a); //两边字符数量差
//		ll tcha = cha;
//		printf("i:%d j:%d ", i, j); 
//		if (s[i].c == s[j].c) {
//			//！！！可以让小的一边加上，也可以让大的一边减去，应选择最优值 
//			ll tans = ans;
//			if (s[i].a > s[j].a) {
//				tans += cha;
//				s[i + 1].a += cha;
//			} else {
//				tans += cha;
//				s[j - 1].a += cha;
//			}
//			i++, j--;
//		} else {
//			//处理两边字符不相同的情况 
//			// 两边不同时，必须将其中一边全部改变，显然只能将少的一边全都改成大的一边
//			// 注意，小的一边不能保证完全与大的一边对称，需要i + 1或j - 1位置继续改变 
//			if (s[i].a < s[j].a) {
//				// ans组成部分：小的一边一定会全改，剩余的进while 
//				ans += s[i].a;
//				printf("ans1:%d ", ans); 
//				while (cha > 0 && i + 1 < j) { //循环直到差值为0，此时两边相同 
//					ll tmp = s[i + 1].a;
//					ans += min(cha, tmp);
//					s[++i].a -= cha;
//					cha -= tmp;
//				}
//				printf("ans2:%d ", ans);
//			} else {
//				//同理 
//				ans += s[j].a;
//				printf("ans1:%d ", ans); 
//				while (cha > 0 && i + 1 < j) {
//					ll tmp = s[j - 1].a;
//					ans += min(cha, tmp);
//					s[--j].a -= cha;
//					cha -= tmp;
//				}
//				printf("ans2:%d ", ans); 
//			}
//		}
//	}
//	cout << ans << '\n';

