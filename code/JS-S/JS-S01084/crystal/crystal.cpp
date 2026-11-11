#include <bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(int i = a; i <= b; i++)
#define For2(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N = 1e6 + 5;
inline ll read() {
    ll x = 0,fl = 1; char c = getchar();
    while (!isdigit(c)) {{if (c == '-') fl = -1;}c = getchar();}
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * fl;
}
int n;
ll m,a[N],sum[N];
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n = read(); m = read();
    For (i,1,n) a[i] = read();
    sort(a + 1,a + n + 1);
    For (i,1,n) sum[i] = sum[i-1] + a[i];
    int ans = 1;
    int l = 1,r = 1; //representing the current sequence is [l,r]
    while (r <= n) {
        while (a[r] * (0LL + r - l + 1) - (sum[r] - sum[l-1]) > m) l++;
        ans = max(ans,r-l+1);
        r++;
    }
    cout << ans << endl;
    return 0;
}
