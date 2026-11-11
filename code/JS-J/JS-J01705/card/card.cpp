#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;

int n, m;
int a[500010];
int ans[300010];
vector<int> cards;

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            auto it = --cards.end();
            for(int k = cards.size() - 1; k >= 0; k--, it--) {
                if(cards[k] == a[j]) {
                    cards.erase(it, cards.end());
                }
            }
            cards.push_back(a[j]);
        }
        for(int j = 0; j < cards.size(); j++) {
            ans[cards[j]]++;
        }
        cards.clear();
    }
    for(int i = 1; i <= m; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}
