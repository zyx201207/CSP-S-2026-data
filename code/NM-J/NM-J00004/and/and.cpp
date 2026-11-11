#include<bits/stdc++.h>
using namespace std;
struct str{
    long long x, y, z;
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    long long n, m, ans = -1;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++){
        vector<str> st;
        st.push_back({1, i, a[i]});
        while (!st.empty()){
            str x = st.back();
            st.pop_back();
            if (x.x == m)
                ans = max(ans, x.z);
            else {
                if (x.y + 1 <= n)
                    st.push_back({x.x + 1, x.y + 1, x.z & a[x.y + 1]});
                if (x.y - 1 > 0)
                    st.push_back({x.x + 1, x.y - 1, x.z & a[x.y + 1]});
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
