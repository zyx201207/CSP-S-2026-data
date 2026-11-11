#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
struct Node {
    char c;
    ll a;
} s[MAXN];
ll sum[MAXN];
ll n, total;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    if(n <= 500) {
        string ans = "";
        for(ll i = 1; i <= n; i ++) {
            cin >> s[i].a >> s[i].c;
            for(int j = 1; j <= s[i].a; j ++) {
                ans += s[i].c;
            }
        }
        int x = ans.size() / 2;
        string sub1 = "";
        for(int i = 0; i < x; i ++) {
            sub1 += ans[i];
        }
        string sub2 = "";
        if(ans.size() / 2 == 0) {
            for(int i = x; i < ans.size(); i ++) {
                sub2 += ans[i];
            }
        } else {
            for(int i = x + 1; i < ans.size(); i ++) {
                sub2 += ans[i];
            }
        }
        int l = 0;
        int r = x - 1;
        while(l <= x - 1) {
            if(sub1[l] != sub2[r]) {
                total ++;
            }
            l ++;
            r --;
        }
        cout << total;
    } else {
        for(ll i = 1; i <= n; i ++) {
            cin >> s[i].a >> s[i].c;
        }
        cout << n / 2;
    }
    return 0;
}
/*
luogu uid:1658585
yi jiu T2 gua le,wo zhen mei zhao le a a a a.
QwQ, QwQ, QwQ, QwQ, QwQ, QwQ
wo yao shang JX xing wei mi huo da shang
*/
