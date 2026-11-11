#include <bits/stdc++.h>
using namespace std;

long long a[500005];
long long b[500005];
long long ans[300005];

bool tmp(long long a, long long b) {
    return a < b;
}

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    for(long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(long long i = 0; i < n; i++) {
        long long cur = 0;
        for(long long j = 0; j <= n; j++) b[j] = 0;
        for(long long k = i; k < n; k++) {
            long long card = a[k];
            bool tf = false;
            long long t = cur;
            for(int j = 0; j < cur; j++) {
                if(b[j] == card) {
                    tf = true;
                    t = j;
                }
                if(tf) b[j] = 0;
            }
            cur = t;
            b[cur] = card;
            cur += 1;
        }
        sort(b, b + cur, tmp);
        long long tt = b[0];
        ans[tt] += 1;
        for(long long mm = 1; mm < n; mm++) {
            if(b[mm] == tt) {
                continue;
            }
            else {
                tt = b[mm];
                ans[tt] += 1;
            }
        }
    }
    for(long long i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
// ZZH39399