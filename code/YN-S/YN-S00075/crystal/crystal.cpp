#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const LL Maxn = 5e5 + 5;

LL A[Maxn];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL a_n, mxq_m;
    cin >> a_n >> mxq_m;
    for (LL i = 1; i <= a_n; ++i)  cin >> A[i];

    sort(A + 1, A + a_n + 1);

    LL L = 1, ad_sum = 0, jsum = 0;
    LL res = 1;
    for (LL R = 1; R <= a_n; ++R) {
        ad_sum = (R - L + 1) * A[R];
        jsum += A[R];
        while (ad_sum - jsum > mxq_m) {
            ad_sum -= A[R];
            jsum -= A[L];
            ++L;
        }

        if (ad_sum - jsum <= mxq_m)  res = max(res, R - L + 1);
    }

    cout << res;


    return 0;
}
