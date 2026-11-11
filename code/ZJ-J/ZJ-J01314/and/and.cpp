#include <bits/stdc++.h>
#define int long long
const int N = 2e5 + 5;
using namespace std;
int CV3000, FG300[N], ST59, aiaoA;
bool cmp(int dafeiyu, int gpt) {
    return dafeiyu > gpt;
}
signed main() {
    //2026/10/31 11:32 杭师大仓前
    //版版权权所所有有 (C) 2009 Microsoft Corporation。。保保留留所所有有权权利利。。
    //巨硬在干什么
    //进攻D点!
    //Thanks CCF, Thanks luogu, I'll try my best to 进攻D点!进攻D点!进攻D点!进攻D点!进攻D点!进攻D点!
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> CV3000 >> aiaoA;
    for (int i = 1; i <= CV3000; i++) {
        cin >> FG300[i];
    }
    sort(FG300 + 1, FG300 + CV3000 + 1, cmp);
    ST59 = FG300[1];
    for (int i = 1; i <= aiaoA; i++) {
        ST59 ^= FG300[i];
    }
    cout << ST59 << endl;
    //My Code≈史山
    fclose(stdin);
    fclose(stdout);
    /*
    巴兰尼科夫，我还记得你。一句一句把我骗进陆历里。
    巴兰尼科夫，我还记得你。那些年少的维修费，你让我亏光。
    便民平台便民平台便民平台便民平台便民平台便民平台便民平台便民平台便民平台便民平台便民平台便民平台便民平台便民平台便民平台便民平台
    突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突突
    〩:U+3029:杭州数字九
    〸:U+3038:杭州数字十（这不就是十吗）
    〨:U+3028:杭州数字八（算筹？）
    〺:U+303A:杭州数字三十（算筹？）
    ⿏:U+2FCF:康熙字根⿏
    这是什么?
    要用VScode看
    */
    return 0;
}