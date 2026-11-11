#include <bits/stdc++.h>
using namespace std;
struct e{
    int a;
    char c;
}l[200005];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i].a >> l[i].c;
    }
    int ii = 0, jj = n;
    while(ii <= jj) {
        int x, y;
        if (l[ii].c == l[jj].c) {
            int p = l[ii].a, q = l[jj].a;
            if (p < q) {
                ii++;
                l[jj].a -= p;
            }
            else if(p == q) {
                    ii++;
                    jj--;
            }
            else {
                jj--;
                l[ii].a -= q;
            }
        }
        else {
            ans += min(l[ii].a, l[jj].a);
            int p = l[ii].a, q = l[jj].a;
            if (p < q) {
                ii++;
                l[jj].a -= p;
            }
            else if(p == q) {
                    ii++;
            jj--;
            }
            else {
                jj--;
                l[ii].a -= q;
            }
        }
        }

    cout << ans;
    return 0;
}
