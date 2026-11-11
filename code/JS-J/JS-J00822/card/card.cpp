#include <bits/stdc++.h>
using namespace std;

#define pdb(expr) (cout << #expr ": " << (expr) << "\n")
#define redirect(file) freopen(file ".in", "r", stdin); \
    freopen(file ".out", "w", stdout);
constexpr char BInf = 0x3F;
constexpr int Inf = 0x3F3F3F3F;
using ll = long long;
using ull= unsigned long long;

int n, m;
int c[500001];
int r[500001];
bool status[300001];
vector<int> st;

int main() {
	redirect("card")
    cin >> n >> m;
    for (int i = 1; i <=n; i++) {
        cin >> c[i];
    }
    memset(status, 0, sizeof status);
    memset(c, 0, sizeof c);
    for (int round = 1; round <= n; round++) {
        for (int card = round; card <= n; card++) {
            int cardpoint = c[card];
            if (status[cardpoint]) {
                while (st.back() != cardpoint) {
                    int cp = st.back();
                    status[cp] = 1;
                    st.pop_back();
                }
            } else {
                status[cardpoint] = 1;
                st.push_back(cardpoint);
            }
        }
        for (int a : st) {
            if (a == round)
                r[]
        }
        st.clear();
    }
}
