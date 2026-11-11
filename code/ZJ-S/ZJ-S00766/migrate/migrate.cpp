#include<iostream>

using i64 = long long;
using pi64 = std:: pair<long long, long long>;

constexpr i64 MAXN = 2000000;
constexpr i64 INF = LLONG_MAX >> 4;

i64 T, C, N, D, A[1 + MAXN];
i64 tp1[1 + MAXN], tp2[1 + MAXN], cnt1[1 + MAXN], cnt2[1 + MAXN], del1[1 + MAXN], del2[1 + MAXN + 1];
i64 res1[1 + MAXN], res2[1 + MAXN], ans, lim1[1 + MAXN], lim2[1 + MAXN];

void solve(){
    std:: cin >> N >> D;
    ans = 0;
    for (int i = 1 ; i <= N ; i++) std:: cin >> A[i], 
    cnt1[i] = cnt2[i] = del1[i] = del2[i]
     = res1[i] = res2[i] = lim1[i] = lim2[i] = 0;
    for (int i = 1, rpos = 1; i <= N - 1 ; i++){
        while (rpos <= N && A[rpos] - A[i] <= D) rpos++;
        tp1[i] = rpos - 1, cnt1[rpos - 1]++;
        if (lim1[rpos - 1] == 0) lim1[rpos - 1] = i;
    }
    for (int i = N, lpos = N ; i >= 2 ; i--){
        while (lpos >= 1 && A[i] - A[lpos] <= D) lpos--;
        tp2[i] = lpos + 1, cnt2[lpos + 1]++;
        if (lim2[lpos + 1] == 0) lim2[lpos + 1] = i;
    }
    for (int i = 1 ; i <= N ; i++){
        res1[i] = cnt1[i];
        del1[tp1[i]]++, del1[i] += del1[i - 1];
        if (del1[lim1[i]] == lim1[i] - 1) res1[i] += res1[lim1[i]];
    }
    for (int i = N ; i >= 1 ; i--){
        res2[i] = cnt2[i];
        del2[tp2[i]]++, del2[i] += del2[i + 1];
        if (del2[lim2[i]] == N - lim2[i]) res2[i] += res2[lim2[i]];
        // std:: cout << res2[i] << ' ';
    }
    for (int i = 2 ; i < N - 1 ; i++){
        ans += res2[i] * res1[i + 1];
    }
    std:: cout << ans << '\n';
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    std:: ios:: sync_with_stdio(false);
    std:: cin.tie(nullptr);
    std:: cin >> C >> T;
    while (T--){
        solve();
    }
    return 0;
}