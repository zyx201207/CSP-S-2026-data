#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

constexpr int N = 5e5 + 1;
constexpr int M = 3e5 + 1;
int n, m;
int a[N];
int card_que[N];
int *qhead = card_que + 1;
int *qtail = card_que + 1;
int *last_idx[M];
int ans_buc[M];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            if (last_idx[a[j]] != 0) {
                int *p = last_idx[a[j]];
                while (p < qtail) {
                    last_idx[*(qtail - 1)] = 0;
                    --qtail;
                }
                *qtail = a[j];
                last_idx[a[j]] = qtail;
                ++qtail;
            } else {
                *qtail = a[j];
                last_idx[a[j]] = qtail;
                ++qtail;
            }
        }
        while (qhead < qtail) {
            ++ans_buc[*qhead];
            ++qhead;
        }
        qhead = card_que + 1;
        qtail = card_que + 1;
        memset(last_idx, 0x00, sizeof(last_idx));
    }
    for (int i = 1; i <= m; ++i) {
        cout << ans_buc[i] << (i == m ? '\n' : ' ');
    }
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}