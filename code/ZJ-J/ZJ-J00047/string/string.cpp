#include <bits/stdc++.h>
using namespace std;
const long long INF = LLONG_MAX >> 1;
//CSP-J 2026 RP+=INF
#define ll long long

struct Node {
    int a;
    char ch;
} nd[200005];

int n, l, r;
ll ans;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    r = n;
    for(int i = 1; i <= n; i++) {
        cin >> nd[i].a >> nd[i].ch;
    }
    while(l != r) {
        if(nd[l].ch != nd[r].ch) {
            if(nd[l].a > nd[r].a) {
                nd[l].a -= nd[r].a;
                ans += nd[r].a;
                r--;
            } else if(nd[l].a < nd[r].a) {
                nd[r].a -= nd[l].a;
                ans += nd[l].a;
                l++;
			} else {
				ans += nd[l].a;
				if(r - l == 1) {
					break;
				}
				l++, r--;
			}
        } else {
            if(nd[l].a > nd[r].a) {
                nd[l].a -= nd[r].a;
                r--;
            } else if(nd[l].a < nd[r].a) {
                nd[r].a -= nd[l].a;
                l++;
            } else {
				if(r - l == 1) {
					break;
				}
				l++, r--;
			}
        }
    }
    cout << ans;
    return 0;
}
