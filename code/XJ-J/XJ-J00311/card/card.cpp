#include <iostream>
#include <vector>
#include <stack>
using std::cin;
using std::cout;

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    std::stack<int> st;
    std::vector<bool> ind(m + 1, 0);
    std::vector<int> ans(m + 1, 0);

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            if (ind[a[j]]) {
                while (st.top() != a[j]) {
                    ind[st.top()] = 0;
                    st.pop();
                }
            } else {
                ind[a[j]] = 1;
                st.push(a[j]);
            }
        }

        for (int c = 1; c <= m; ++c)
            ans[c] += ind[c], ind[c] = 0;

        while(!st.empty())
            st.pop();
    }

    for (int i = 1; i <= m; ++i)
        cout << ans[i] << ' ';
    cout << '\n';
}

