#include <iostream>
#include <vector>

using ll=long long;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<ll> appes(n+1, 0), sum1(n+1, 0), sum2(n+1, 0);
    ll len=0;
    std::vector<char> chs(n+1, 0);
    for(int i=1; i<=n; i++) std::cin >> appes[i] >> chs[i], sum1[i]=(len += appes[i]);
    ll ans=0;
    sum2[n]=appes[n];
    for(int i=n-1; i>=1; --i) sum2[i]=sum2[i+1]+appes[i];
    for(ll L=1, R=n, l=1, r=len; l <= r; ) {
        ll nxtr=sum1[R-1], nxtl=sum1[L]+1;
        ll dl=nxtl-l, dr=r-nxtr;
        ll d=std::min(dl, dr);
        //std::cerr << l << ' ' << r << ' ' << L << ' ' << R;
        if(chs[L] != chs[R]) ans += d;//, std::cerr << ", ans += " << d;
        //std::cerr << '\n';
        l += d, r -= d;
        if(l==nxtl) ++L;
        if(r==nxtr) --R;
    }
    std::cout << (ans);
}
