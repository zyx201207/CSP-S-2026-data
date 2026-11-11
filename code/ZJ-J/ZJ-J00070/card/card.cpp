// 8:58 T1 样例测试通过 预期得分：100
// 9:20 T2 样例测试通过 预期得分：200
// 9:23 开 T3, 不知道能不能做出来
// 9:32 这是背包板子吗？
// 这是诈骗吗？ ？！骗骗！？
// 那我可先按诈骗思路写了
// OK，不是诈骗
// 对呀 T3 怎么会这么简单
// Python 骗我 524288 & 262144 = 262144 ，SB Python
// 嘶，背包板子怎么写来着？
// 算了，开 T4 看看
// 不会正解，暴力来
// 10:45 T3 50 分暴力 预期250
// 我怎么这么菜
// 11:37 T4 O(n^3) 暴力， 预期274
// CCF 的机子好像会比学校的快不少，但是 1s 过 1e12 应该还是不行
// 现在我只希望 T1 T2 别挂分就行
// 274pts 能有 5 级勾吗
// 算了下午还有 S 组呢
// 11:55 封包, 不写了

#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, a[N], ans[M];
int st[N], top = 0;

bool check() {
    for(int i = 1; i < n; i++) {
        if(a[i] > a[i+1]) return 0;    
    }
    return 1;
}

int main() {
    // freopen("card.in", "r", stdin);
    // freopen("card.out", "w", stdout);
    
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    // cout << check() << endl;    
    for(int i = 1; i <= n; i++) {
        top = 0;
        for(int j = i; j <= n; j++) {
            bool flag = 0;
            for(int k = 1; k <= top; k++) {
                if(st[k] == a[j]) {
                    flag = 1;
                    top = k - 1;
                    st[++top] = a[j];
                }
            }
            if(!flag) {
                st[++top] = a[j];
            }
        }
        for(int j = 1; j <= top; j++) 
            ans[st[j]]++;
        // for(int j = 1; j <= m; j++)
        //     cout << ans[j] << " ";
        //     cout << endl;
    }
    for(int i = 1; i <= m; i++)
        cout << ans[i] << " ";
    return 0;
}