#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; --i)
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f3f3f3f3f;
string c1, c2, s1, s2;
bool ans[4];
bool chck1(string a, string b) {
	return a[0] == b[0] and a[1] == b[1];
}
bool chck2(string a, string b) {
	char ch1 = a[2], ch2 = b[2]; 
	return ((ch1 == 'A' or ch1 == 'B' or ch1 == 'C') and (ch2 == 'A' or ch2 == 'B' or ch2 == 'C')) or ((ch1 == 'D' or ch1 == 'F') and (ch2 == 'D' and ch2 == 'F'));
} 
bool chck3(string a, string b) {
	char ch1 = a[2], ch2 = b[2]; 
	switch (ch1) {
		case 'A': {
			return ch2 == 'B';
			break;
		}
		case 'B': {
			return ch2 == 'A' or ch2 == 'C';
			break;
		}
		case 'C': {
			return ch2 == 'B';
			break;
		}
		case 'D': {
			return ch2 == 'F';
			break;
		}
		case 'F': {
			return ch2 == 'D';
			break;
		}
	}
} 
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	ans[0] = (c1 == c2);
	ans[1] = (ans[0] and chck1(s1, s2));
	ans[2] = (ans[1] and chck2(s1, s2));
	ans[3] = (ans[2] and chck3(s1, s2));
	rep(i, 0, 3) {
		cout << ans[i];
	}
}
/*
//freopen
frepoen
froepen
SD-S00999祭。
goal：J 300+, S 1= 
退役快乐！
password： Trick||Treat! 
考虑双指针。 
开题顺序：BACD
同车厢当且仅当c1 == c2
同排当且仅当同车厢且s1, s2前两位相同，写个chck。 
同侧当且仅当同排且同为ABC或DF
相邻当且仅当同侧且(&&^*(&^%(*^( 
*/
