#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

int n, ne1[N], ne2[N];
long long d, x[N], s0[N], s1[N], s2[N], s3[N], ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int c, t;
    cin >> c >> t;
    while(t--) {
        cin >> n >> d;
        for(int i = 1;i <= n;i++) {
            cin >> x[i];
        }
        memset(ne1, 0, sizeof(ne1));
        memset(ne2, 0, sizeof(ne2));
        memset(s0, 0, sizeof(s0));
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
        memset(s3, 0, sizeof(s3));
        for(int l = 1, r = 1;l < n;) {
            if(r == n || x[r + 1] > x[l] + d) {
                if(l < r) ne1[l] = r;
                if(l < r - 1) ne2[l] = r - 1;
                l++;
            }
            else r++;
        }
        ans = 0;
        for(int i = 1;i < n;i++) {
            if(ne1[i]) s0[i] = ne1[i] - i;
        }
        for(int i = n - 1;i > 0;i--) {
            if(ne1[i] == 0) {
                cout << s1[i] << " " << s2[i] << " " << s3[i] << endl;
                continue;
            }
            if(ne1[ne1[i]] == 0) {
                s1[i] = 0;
            }
            else {
                if(ne1[ne1[i]] > d + x[ne1[i] - 1]) s1[i] = s1[ne1[i]];
                s1[i] += ne1[ne1[i]] - ne1[ne1[i] - 1];
            }
            if(ne2[i] == 0 || ne1[ne2[i]] == ne1[i]) {
                s2[i] = s2[ne1[i]];
                s3[i] = s2[i];
                cout << s1[i] << " " << s2[i] << " " << s3[i] << endl;
                continue;
            }
            if(ne2[ne1[i]] > d + ne2[i]) {
                s2[i] = s2[ne1[i]] + ne1[ne2[i]] - ne1[ne1[i] - 2];
                s3[i] = s2[ne1[i]];
            }
            else if(ne1[ne1[i]] > d + ne2[i]) {
                s2[i] = s3[ne1[i]] + ne1[ne2[i]] - ne1[ne1[i] - 2];
                s3[i] = s3[ne1[i]];
            }
            else {
                s2[i] = s1[ne1[i]] + ne1[ne2[i]] - ne1[ne1[i] - 2];
                s3[i] = 0;
            }
            ans += s2[i];
            cout << s1[i] << " " << s2[i] << " " << s3[i] << endl;
        }
        cout << ans << endl;
    }
    return 0;
}
