#include <bits/stdc++.h>

const int N(2000000);

int n;

long long d, a[N+5];

void solve() {
    std::cin>>n>>d;
    for(int i(1); i<=n; i++) std::cin>>a[i];
    long long gap(d/(a[2]-a[1]));
    if(gap<=1 || 2*gap-1>n) {
        std::cout<<"0\n"; return ;
    }
    std::cout<<n-2*gap+1<<"\n";
}

int main() {
    std::freopen("migrate.in", "r", stdin);
    std::freopen("migrate.out", "w", stdout);
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int c, t; std::cin>>c>>t;
    while(t--) solve();
    return 0;
}

// 8pts at 230 min