/* bushi, ni zhege jianpan shift jian yizhi zai zhouji wode zuoshou xiaozhi???
   bushi, xian zai 14:17 wo jianqiaoyan yijing fan le...
   bushi, ni zhege meishi jianwei ling wode '\' '|' xuanzhuan...
   ```````````````````````````````````````````````````````````````````````````
   jingran you baocuo!! zanqie bu hei le.
   ```````````````````````````````````````````````````````````````````````````
   15:32 crystal samples passed. tiao le yige shiji de yuanyin shi mei paixu. wo shi ruozhi...
   15:37 jixian shuju WA le, yuyuzheng
   15:41 zenme shi shengchengqi gua le, xiao si. zhexia guo le.
*/
#include <bits/stdc++.h>
using namespace std;

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    
    i64 n, m;
    cin >> n >> m;
    vector<i64> a(n + 1);
    vector<i64> pre(n + 1);
    for(i64 i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    for(i64 i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    
    auto check = [&](i64 l, i64 r, i64 val) {
        if((pre[r] - pre[l - 1]) + m >= val * (r - l + 1)) return true;
        else return false;
    };

    i64 ans = 1;
    for(i64 i = 1; i <= n; i++) {
        i64 lo = 1, hi = i, res = hi;
        while(lo <= hi) {
            i64 mid = (lo + hi) / 2;
            if(check(mid, i, a[i])) res = mid, hi = mid - 1;
            else lo = mid + 1;
        }
        ans = max(ans, i - res + 1);
        // cerr << res << ' ' << i << '\n';
    }
    cout << ans << '\n';
    return 0;
}