#include<bits/stdc++.h>

using i64 = long long;

constexpr i64 MAXN = 500000;

i64 N, M, A[1 + MAXN];

bool check(i64 X){
    i64 np = X, res = 0;
    for (int i = 1 ; i < X ; i++){
        res += A[X] - A[i];
    }
    if (res <= M) return true;
    for (np = X + 1 ; np <= N ; np++){
        res -= (A[np - 1] - A[np - X]);
        res += (A[np] - A[np - 1]) * (X - 1);
        if (res <= M) return true;
    }
    return false;
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    std:: ios:: sync_with_stdio(false);
    std:: cin.tie(nullptr);
    std:: cin >> N >> M;
    for (int i = 1 ; i <= N ; i++){
        std:: cin >> A[i];
    }
    std:: sort(A + 1, A + N + 1);
    i64 l = 1, r = N + 1;
    while (r - l > 1){
        i64 mid = (l + r) >> 1;
        if (check(mid)){
            l = mid;
        } else {
            r = mid;
        }
    }
    std:: cout << l << '\n';
    return 0;
}
