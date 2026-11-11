#include <bits/stdc++.h>

const int N(500000);

int n;

long long m;

long long a[N+5], b[N+5];

int main() {
    std::freopen("crystal.in", "r", stdin);
    std::freopen("crystal.out", "w", stdout);
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    std::cin>>n>>m;
    for(int i(1); i<=n; i++) std::cin>>a[i];
    std::sort(a+1, a+n+1);
    for(int i(1); i<=n; i++) b[i]=a[i]+b[i-1];
    int ans(1);
    for(int i(1); i<=n; i++) {
        int len(0);
        for(int j(20); j>=0; j--) {
            int next(len+(1<<j));
            if(next>i) continue;
            if(a[i]*next-b[i]+b[i-next]<=m) len=next;
        }
        ans=std::max(ans, len);
    }
    std::cout<<ans;
    return 0;
}

// 100pts at 9 min