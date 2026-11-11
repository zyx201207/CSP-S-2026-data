#include <iostream>
#include <stack>
#include <unordered_set>
using namespace std;

int cnt[3001];
int ls[5001];
int n;
int block[5001];
int cur = 1;

void play(int beg) {
    stack<int> s;
    unordered_set<int> se;
    for (int i = beg; i <= n; i++) {
        if (se.count(ls[i])) {
            while (ls[s.top()] != ls[i]) {
                se.erase(ls[s.top()]);
                block[s.top()] = cur;
                s.pop();
            }
            cur++;
        }
        else {
            s.push(i);
            se.insert(ls[i]);
        }
    }
    for (int x : se) cnt[x]++;
}


signed main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> ls[i];
    }
    for (int i = 1; i <= n; i++) {
        play(i);
    }
    for (int i = 1; i <= m; i++) {
        cout << cnt[i] << " ";
    }
}
