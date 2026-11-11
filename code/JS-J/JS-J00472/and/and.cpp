#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, m, a[N];
int suff = 0;
int check1(int a) {
    int ans = 0;
    for (int i = 0;i < suff;i++) {
        ans += a & 1;
        a = a >> 1;
    }
    return ans;
}

bool cmp(int a, int b) {
    int checka = check1(a), checkb = check1(b);
    if (checka != checkb){
        return checka > checkb;
    } else {
        return (a % (1 << (suff + 1))) >= (b % (1 << (suff + 1)));
    }
}
long long num[60];
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        int x = 1,cnt = 0;
        cin >> a[i];
        while (true) {
            if (x > a[i] && a[i] >= x / 2) {
                num[cnt]++;
                break;
            }
            x *= 2;
            cnt++;
        }
    }
    int x = m;
    for (int i = 50;i >= 0;i--) {
        x -= num[i];
        if (x <= 0) {
            suff = i;
            break;
        }
    }

    sort(a, a + n,cmp);
    long long ans = a[0];
    for (int i = 1;i < m;i++) {
        ans = ans & a[i];
    }

    cout << ans;

    return 0;
}
