#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
ll n, ans;
ll num[N];
char b[N];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll cnt = 0;
    for(int i = 1;i <= n;++i) {
        cin >> num[i] >> b[i];
        cnt += num[i];
    }
    ll l = 1, r = cnt, head = 1, tail = n;
    while(l <= cnt / 2) {
        if(head == tail) {
            break;
        }
        if(b[head] != b[tail]) {
            if(num[head] < num[tail]) {
                num[tail] -= num[head];
                ans += num[head];
                l += num[head];
                head++;
            } else {
                num[head] -= num[tail];
                l += num[tail];
                ans += num[tail];
                tail--;
            }
        } else {
            if(num[head] < num[tail]) {
                num[tail] -= num[head];
                l += num[head];
                head++;
            } else {
                num[head] -= num[tail];
                l += num[tail];
                tail--;
            }
        }
    }
    cout << ans;
    return 0;
}
