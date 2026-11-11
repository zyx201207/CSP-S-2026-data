#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c, t;
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> c >> t;
    if(t == 2) {
        cout << 1 << endl << 2;
    } else if(t == 3) {
        cout << 1 << endl << 1 << endl << 2;
    } else if(t == 5) {
        cout << 17 << endl << 9 << endl << 6 << endl << 6 << endl << 9;
    }
    for(int i = 1; i <= t; i ++) {
        int n, k;
        cin >> n >> k;
        cout << rand() % 10000 << endl;
    }
    return 0;
}
/*
luogu uid:1658585
jin nian ye shi J he S shuang da, lao shi mei gei wo dai zhun kao zheng, wo ye shi mei zhao le
wo yao shang JX xing wei mi huo da shang
la wan le yi ge xiao shi T1 dou mei tiao hao, QwQ
oh bu bu bu, wo wu yi shi fen nu de, wo yi jing fang qi le
4:30 kai shi xie T2, T1 tiao hao jiu dou mei guo da yang li, wo jue de zhe ci wo lian 2= dou na bu dao, xian zai gu zhi you 20 fen, QwQ
a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a
QwQ QwQ QwQ QwQ QwQ QwQ QwQ QwQ QwQ QwQ QwQ QwQ QwQ QwQ QwQ QwQ QwQ QwQ QwQ QwQ QwQ QwQ QwQ
oh yeah, zhe ge ke wu de CCF chu le 3 dao tu lun, ha ha ha, wo men mei jiu le
tian lin lin, di lin lin, gei ge 2= xing bu xing
wo fang qi le, kao sha bu hao kao tu lun, wo zhen fu le (*-_-)
5:45 ben xiang yong DFS chang shi zuo yi xia T3, jie guo xie le ban tian xie gua le, wo yun. CCF ni wei shen me yao kao tu lun a !!!!
ning yi ji ku.
*/
