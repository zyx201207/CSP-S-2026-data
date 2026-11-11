#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long a[N];
// Welcome to watch my bad passages and code, my name is Chan.

// How can i use the Chinese to write my word.
// I'm not good at English, so if my code was published by someone on Luogu, have anyone answer my question?
// I guess no one can understand my sentences.

// I try to install the Chinese package, but i don't know the password of NOI.
// 11:36 Someone give their code and wanna go back, I felt so anxiety.
// In my right, a boy asked many strange questions.
// I guess it was his first time to attend the CSP.
// Oh, I write so bad. /(* o *)\

// The first n is the number i will choose.
// The second n is the how many number was chose by me.
// The 2 is i choose the number or not.

// Oct. 31
int n, m;
long long maxn;
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    srand(time(0));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        // I think it is 01 bag problem plus, but i didn't learnt it carefully, QWQ.
        // dp[i][1][1] = a[i];
        // 11:13 I give up to write the complete code.
        maxn = max(maxn, a[i]);
    }
    sort(a + 1, a + 1 + n);
    // Case 1: I can only choose one number.
    if (m == 1)
        cout << maxn;
    // Case 2: I must choose all the number.
    else if (m == n) {
        long long ans = a[1];
        for (int i = 1; i <= n; i++) {
            ans &= a[i];
        }
        cout << ans;
    }
    else if (m == 2) {
        long long ans = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans;
    }
    else {
        long long ans = a[n];
        for (int i = n; i >= n - m + 1; i--)
            ans &= a[i];
        cout << ans;
    }
    cout << endl;


    /*
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; i <= n; i++) {
            dp[j][][1] = max()
        }
    }
    */
    return 0;
}
// I more like to use VScode, but when i practice how to use the NOI Linux, i used the Code::Blocks IDE.
