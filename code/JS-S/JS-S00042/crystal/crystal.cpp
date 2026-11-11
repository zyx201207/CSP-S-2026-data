#include <bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define dep(i,r,l) for(int i = r; i >= l; i--)
#define lc (idx << 1)
#define rc (idx << 1 | 1)

using namespace std;

int m, n;
const int maxn = 5e5 + 200;
int a[maxn], c[maxn];

bool check(int len){
    rep(i,1,(n - len + 1)){
        int rig = (i + len - 1);
        int opt = len * a[rig] - (c[rig] - c[i - 1]);
        if(opt <= m){
            return true;
        }
    }
    return false;
}

bool cmp(int a, int b){
    return a < b;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    rep(i,1,n){
        cin >> a[i];
    }
    sort(a+1, a+1+n, cmp);

    rep(i,1,n){
        c[i] = c[i-1] + a[i];
    }
    int l = 1, r = n;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << r << "\n";

    return 0;
}