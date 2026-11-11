#include <iostream>
#include <stack>
using namespace std;

const int N = 5e5 + 5;

int n, m, tmp, sa;
int a[N], ans[N], pre[N];
bool now[N];

stack<int> st;

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    tmp = 0, sa = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = i;
        if (a[i] != tmp) {
            for (int j = sa; j < i; j++) {
                pre[j] = i - 1;
            }
            tmp = a[i];
            sa = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            j = pre[j];
            if (!now[a[j]]) {
                st.push(a[j]);
                now[a[j]] = 1;
            } else {
                while (!st.empty()) {
                    if (st.top() != a[j]) {
                        now[st.top()] = 0;
                        st.pop();
                    } else {
                        break;
                    }
                }
            }
        }
        while (!st.empty()) {
            ans[st.top()]++;
            now[st.top()] = 0;
            st.pop();
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}
