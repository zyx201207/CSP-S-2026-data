#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> ans(m + 1, 0);
    for (int round = 1; round <= n; round++) {
        vector<int> cards;
        for (int i = round; i <= n; i++) {
            auto it = find(cards.begin(), cards.end(), a[i]);
            if (it != cards.end()) {
                cards.erase(it, cards.end());
            }
            cards.push_back(a[i]);
        }
        for (int i = 0; i < cards.size(); i++) {
            ans[cards[i]]++;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
