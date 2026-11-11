// #define NDEBUG
#include<bits/stdc++.h>
#ifdef NDEBUG
#define print(...) void()
#else
#define print(...) void(fprintf(stderr, __VA_ARGS__))
#endif
#define up(i,l,r) for (int i=l; i<=r; ++i)
#define dn(i,r,l) for (int i=r; i>=l; --i)
using ll = long long; using namespace std;
const int N = 5e5+5;
int n;ll m;
ll A[N];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    up (i, 1, n) cin >> A[i];
    sort(A+1, A+1+n);
    ll sum=0;int l=1;
    int ans=0;
    up (r, 1, n){
        sum+=(r-l)*(A[r]-A[r-1]);
        while (sum>m) sum-=A[r]-A[l], ++l;
        ans=max(ans,r-l+1);
    }
    cout << ans;
    return 0;
}