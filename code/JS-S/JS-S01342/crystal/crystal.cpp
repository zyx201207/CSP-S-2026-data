#include <iostream>
#include <vector>
#include <algorithm>

using ll=long long;

constexpr int maxn=5e5+10;

ll w[maxn];

int n; ll m;

bool check(int len) {
    ll sum=0, mopt;
    for(int i=1; i<=len; i++) sum += w[i];
    mopt=len*w[len]-sum;
    for(int right=len+1; right<=n; right++) {
        sum += w[right];
        sum -= w[right-len];
        mopt=std::min(mopt, len*w[right]-sum);
    }
    return mopt <= m;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    for(int i=1; i<=n; i++) std::cin >> w[i];
    std::sort(w+1, w+n+1);
    int left=1, right=n, mid, ans=1;
    while(left <= right) {
        mid=(left+right)>>1;
        if(check(mid)) left=mid+1, ans=mid;
        else right=mid-1;
    }
    std::cout << ans;
}
