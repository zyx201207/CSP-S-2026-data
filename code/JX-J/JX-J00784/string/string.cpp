#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ts to_string
using namespace std;

struct d { ll s; ll l; char c; };

void log(string cont) {
    cout << cont << "\n";
}

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<d> data;
    bool f = false; d lst;
    ll tt = 1;
    // log("input start");
    for (int i = 0; i < n; i ++) {
        ll a; char c; cin >> a >> c;
        if (!f) {
            lst = {tt, a, c};
            f = true;
        } else if (lst.c == c) {
            lst.l += a;
        } else {
            data.push_back(lst);
            lst = {tt, a, c};
        }
        tt += a;
    }
    data.push_back(lst);
    tt --;
    // log("input finish, tt="+ts(tt));
    
    ll l = 0, r = data.size()-1, cnt = 0;
    for (ll i = 1; i <= tt/2; i ++) {
        if (!(i >= data[l].s && i < data[l].s+data[l].l)) {
            l ++;
        }
        if (!(tt+1-i >= data[r].s && tt+1-i < data[r].s+data[r].l)) {
            r --;
        }
        // log("counting round "+ts(i)+", l="+ts(l)+", r="+ts(r));
        if (data[l].c != data[r].c) {
            // log("diff caught, cnt="+ts(cnt+1));
            cnt ++;
        }
    }
    cout << cnt;
    return 0;
}