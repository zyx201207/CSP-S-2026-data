#include <bits/stdc++.h>
using namespace std;

#define NAME "migrate"
#define CASE
#define int long long
const int N = 2e6+5, mod = 1e9+7;

#define File(name) freopen(name".in", "r" ,stdin), freopen(name".out","w",stdout);
#define For(i,l,r) for (int i = l; i <= r; i++)
#define rFor(i,l,r) for (int i = r; i >= l; i--)
#define rg(c) c.begin(), c.end()
#define ms(c,v) memset(c, v, sizeof v)
#define l first
#define r second
#define endl '\n'
#define ll long long

int qpow(int a, int b, int m = mod) {
    if (b == 0) return 1;
    int v = qpow(a, b>>1, m);
    return (ll)v * v % m * ((b&1)?a:1) % m;
} 

void solve();

signed main() {
    File(NAME);
    int t = 1;
#ifdef CASE
    cin >> t >> t;
#endif
    while(t--) {
        solve();
    }
    return 0;
}

int n, d;
int x[N];
int l[N], r[N];
int cl[N], cr[N];
int rr[N];
int pth[N], np;
void solve() {
    cin >> n >> d;
    For(i,1,n) {
        cin >> x[i];
    }
    int j = 1;
    For(i,1,n) {
        while (x[i]-x[j] > d) j++;
        l[i] = j;
    }
    j=n;
    rFor(i,1,n) {
        while (x[j]-x[i] > d) j--;
        r[i] = j;
    }
    j = 1;
    int ans = 0;
    For(i,1,n) {
        For(j,i+1,n) {
            int k = i;
            np=0;
            bool fail = false;
            while (k < j) {
                pth[++np] = k;
                k=r[k];
                if (k == r[k] && k < j) {
                    fail = 1;
                    break;
                }
            }
            if (fail) continue;
            pth[++np] = j;
            int cnt = 0;
            For(k,1,np-2) {
                int dif = r[pth[k]] - l[pth[k+2]];
                if (dif == 1) cnt++;
                if (dif > 1) cnt = 3;
            }
            if (cnt == 1) ans++;
        }
    }
    cout << ans << endl;
}