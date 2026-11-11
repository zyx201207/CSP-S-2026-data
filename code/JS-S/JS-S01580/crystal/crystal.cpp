#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 5e5 + 5;
int n,m,a[N],ans[N],sa[N];

signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n);
    for(int i = 1; i<= n; i++) {
        sa[i]= sa[i - 1] + a[i];
    }
    int rgt = n,lft = n;
    while(lft >= 1 && rgt >= 1) {
        while(sa[rgt] - sa[lft - 1] + m >= a[rgt] * (rgt - lft + 1)) {
            ans[rgt] = rgt - lft + 1;
            lft--;
        }
        rgt--;
    }
    int maxn = 0;
    for(int i = 1; i<= n;i++) {
        if(ans[i] > maxn) {
            maxn = ans[i];
        }
    }
    cout << maxn << "\n";
    return 0;
}