#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
const int M = 3e5+5;
int n, m;
int a[N];
bool instk[M];
int stk[N];
int top = -1;
int ans[M];

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int now = a[j];
            if (!instk[now]) {
                instk[now] = 1;
                ++top;
                stk[top] = now;
            } else {
                int x = stk[top];
                while (x != now) {
                    instk[x] = 0;
                    top--;
                    x = stk[top];
                }
            }
        }
        while (top >= 0) {
            int x = stk[top];
            instk[x] = 0;
            ans[x] ++;
            --top;
        }
    }

    for (int i = 1; i <= m; ++i){
        cout << ans[i];
        if (i < n) {
            cout << ' ';
        }
    }
    return 0;
}
