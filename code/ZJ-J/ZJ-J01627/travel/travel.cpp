#include<bits/stdc++.h>
//#define int long long
#define endl '\n'
using namespace std;
#define rp(i, a) for(int i = 1; i <= a; i++)
#define rd(i, a) for(int i = 0; i < a; i++)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define per(i, a, b) for(int i = b; i >= a; i--)
#define vt vector
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int c1, c2, flag = 1;
string s1, s2, xx, yy;
char x, y;
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) cout << 1;
	else cout << 0, flag = 0;
	x = s1[2];
	y = s2[2];
	xx = s1.substr(0, 2);
	yy = s2.substr(0, 2);
	if(flag && xx == yy) cout << 1;
	else cout << 0, flag = 0;
	if(flag && !((x <= 'C') ^ (y <= 'C'))) {
		cout << 1;
	} else {
		cout << 0;
		flag = 0;
	}
	if(flag && abs(int(x - y)) == 1) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}
/*
guanzhu "cxh1208" xiexie miao (kaohou keneng hui gaicheng Starlit_Sky)
this keyboard chouren kanle dou shihuai le
shanchujian yao henzhong caineng enxiaqu wode shou haotong a
fu gong o konggejian haihui fachu jianruibaomingsheng
deng wo youqianle jiugei hangshida huandiannao
xiasha xiaoqu zhege jifang zenme zheme re
suanle yaoshiyouqian zai juan yidian kongtiao haole (doge
8:38 queshengyuan finish
wode shou yao tongsi le
shanchujian shenzhi yao lianggeshouzhi cainengenxiaqu (keneng shi wo liqi taixiao le)
woc shengelanyao buxiaoxin ba dangban nongfanle...
zhege "b"jian yeyao henyongli an
turan faxian ziji zuodeshi yaoyaoyi(shuangle
wobuxingle xiewan T2 youdianleile
T4 haoxiangshi moniti
T3 kendingshi 01Trie danwo buxiangxie
shuiyigeyideng jiuxing yinggaibuyong quanzhengjie ba
nawo T3 shuiyixia yong monituihuo yinggaishuodeguoqu ba
ganjue hanshu bodong buda yong monituihuo yinggai nengna tingduo fen
budui nabuliao duoshaofen nahaoba zhineng laolaoshishi xie 01Trie le  
wo hao tang bushi 01Trie 
10:01 T3 finish, so slowly.../dk
T4 kanqilai haochang emmmmm xianqu shangge cesuo xiuxi yixia xixixi
......
......
......
wofule
fashengle yixie bufangbian miaoshu de shiqing, meixinqing xiele nadian baolifen paolu le
10:30 all finish
buguafen 100 + 100 + 100 + 60  
jiuzheyangba yinggai gou 1= le, baofenle bugou jiu shouzhe
geren ganjue nandu : red orange orange/yellow yellow/green  (maybe he qunian chabuduo)
biewen weishenme buxie T4 yinweilan
ruguowo T1/2/3 guafen le wojiucheng jifangxiaochou le dududu
ruguo T4 baoli yeneng bao nagengshi xiaochou dududu
xiawu -s rp++!
*/
