// 15:17 T1 50pts 暴力
// 15:57 T1 二分全部样例通过 预期 100pts 
// 16:30 这个 T2 怎么这么石
// 16:42 有点猜到 T2 是什么了
// 17:00 好麻烦，又要建图还要求最短路
// 怎么写 dij ？
// 我觉得这个 dij 效率很慢，而且图里有大量的重边
// 复杂度高达 O(qnlogm + k^2)
// 嘻嘻, 没救了
// 咦，memset 怎么初始化最大值？ 可以用 LONG_LONG_MAX 吗, 还是说用 0x7f7f7f7f?
// only 100
// 为什么一直 RE 啊啊啊啊啊啊啊啊啊!!!!!!!!!!!!
// 为什么不 relax ？？？？？？
// 120 min 什么也没干，仍然 100pts
// T2 还是没有调出来
// 我果然还是太菜了
// Grade 10 第一次打CSP 100pts 可以退役吗?
// 可是我真的很想打NOIP
// 虽然 whk 还可以, 但是一年之后不知道成什么样
// 可能真的要和 OI 说再见了吧
// 那就这样吧,我的第一次也是最后一次 CSP
// 我期待在迷惑行为大赏上看到我自己

#include <bits/stdc++.h>
using namespace std;

vector <int> a;

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    
    int c, t;
    cin >> c >> t;
    int k;
    while(cin >> k) a.push_back(k);
    k = clock();
    while(t--) {
        cout << a[k % a.size() - 1];
    }
}