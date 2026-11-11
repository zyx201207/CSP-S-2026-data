#include <bits/stdc++.h>
using namespace std;

int n, m, a[200005], z = 0, c[200005];

bool cmp(int a, int b) {
    if (((a >> z) & 1) == ((b >> z) & 1))
        return (a > b);
    else
        return ((a >> z) & 1) > ((b >> z) & 1);
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        int z1 = 0, t = a[i];
        while (t) {
            //printf("%d", t & 1);
            if (t & 1)
                ++c[z1];
            t >>= 1;
            ++z1;
        }
        z = max(z, z1);
        //printf("\n");
    }
    --z;
    int r = n;
    int ans = 0, tmp;
    for (; z >= 0; --z) {
        sort(a + 1, a + 1 + r, cmp);
        tmp = a[1];
        for (int i = 1; i <= m; i++) {
        tmp &= a[i];
        }
        int cnt = 0;
        for (int i = 1; i <= r; i++) {
            if ((a[i] >> z) & 1) cnt++;
        }
    if (cnt >= m && cnt <= r)
            r = cnt;
    ans = max(ans, tmp);
    }
    /*sort(a + 1, a + 1 + r, greater<int>());*/
    /*for (int i = 1; i <= r; i++) {
        ans &= a[i];
        string out = "";
        int t = a[i];
        while (t) {
            out += (t & 1) + '0';
            t >>= 1;
        }
        for (int i = out.length() - 1; i >= 0; i--) cout << out[i];
        cout<<endl;
    }*/
    printf("%d\n", ans);
}
