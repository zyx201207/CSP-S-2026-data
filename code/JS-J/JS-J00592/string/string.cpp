#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,sum;
const int N = 2e5 + 5;
struct node {
    int x;
    char ch;
}s[N];
signed main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    if(n == 1) {
        cout << 0;
        return 0;
    }
    bool flag1 = true,flag2 = true,flag3 = true;
    int maxn = 0;
    for(int i = 1;i <= n;i++) {
        cin >> s[i].x >> s[i].ch;
      //  cout << s[i].ch;
        sum += s[i].x;
        if(i != 1) {
            if(s[i].ch != s[i - 1].ch)
                flag1 = false;
            else
                flag2 = false;
        }
        if(s[i].x != 1)
            flag3 = false;
    }
    if(flag1) {
        cout << 0;
        return 0;
    }
    if(flag2) {
        cout << (n + 1) / 2;
        return 0;
    }
    if(flag3) {
        char s1[sum + 5];
        int len = 0;
        for(int i = 1;i <= n;i++) {
            s1[++len] = s[i].ch;
        }
        int ans = 0;
        for(int i = 1;i <= sum / 2;i++) {
            if(s1[i] != s1[sum - i + 1]) {
                //cout << s1[i] << " " << s1[sum - i + 1] << '\n';
                ans++;
            }
        }
        cout << ans;
        return 0;
    }
    if(sum <= 1e9) {
        char s1[sum + 5];
        int len = 0;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= s[i].x;j++) {
                s1[++len] = s[i].ch;
              //  cout << s1[len];
            }
        }
     //   cout << sum << " ";
        int ans = 0;
        for(int i = 1;i <= sum / 2;i++) {
            if(s1[i] != s1[sum - i + 1]) {
                //cout << s1[i] << " " << s1[sum - i + 1] << '\n';
                ans++;
            }
        }
        cout << ans;
        return 0;
    }
    cout << (sum + 1) / 2;
    /*if()
    int op = 0,pre,ans;
    for(int i = 1;i <= n;i++) {
        if(s[i].ch != s[n - i + 1].ch) {
            if(op == 1 && s[i].x  == s[n - i + 2].x)
                pre -= min(s[i].x,s[n - i])
            ans += pre;
            pre = abs(s[i].x - s[n - i + 1].x);
            if(s[i].x < s[n - i + 1].x)
                op = 1;
            else
                op = -1;
        }
    }
    cout << ans;*/
    return 0;
}
