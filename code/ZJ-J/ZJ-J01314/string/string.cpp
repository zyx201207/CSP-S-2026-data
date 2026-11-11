#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, sensei, ans;
string bvvd;
signed main() {
    //2026/10/31 10:25 杭师大仓前
    //版版权权所所有有 (C) 2009 Microsoft Corporation。。保保留留所所有有权权利利。。
    //巨硬在干什么
    //进攻D点!
    //Thanks CCF, Thanks luogu, I'll try my best to 进攻D点!进攻D点!进攻D点!进攻D点!进攻D点!进攻D点!
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    bvvd += ' ';
    for (int i = 1; i <= n; i++) {
        int c;
        char manbaout;
        cin >> c >> manbaout;
        sensei += c;
        if (c > 600) {
            for (int j = 1; j <= c / 600; j++) {
                for (int k = 1; k < 601; k++) {
                    bvvd += manbaout;
                }
            }
            for (int j = 1; j <= c % 600; j++) {
                bvvd += manbaout;
            }
        }
        for (int j = 1; j <= c; j++) {
            bvvd += manbaout;
        }
    }
    if (sensei % 2) {
        int BYD = sensei / 2;
        for (int i = BYD + 2; i <= sensei; i++) {
            if (bvvd[i] != bvvd[sensei - i + 1]) {
                ans ++;
            }
        }
    } else {
        int BYD = sensei / 2;
        for (int i = BYD + 1; i <= sensei; i++) {
            if (bvvd[i] != bvvd[sensei - i]) {
                ans ++;
            }
        }
    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    /*
    巴兰尼科夫，我还记得你。一句一句把我骗进陆历里。
    巴兰尼科夫，我还记得你。那些年少的维修费，你让我亏光。
    便民平台便民平台便民平台便民平台便民平台便民平台便民平台便民平台便民平台便民平台便民平台便民平台便民平台便民平台便民平台便民平台
    突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突
    */
    return 0;
}