#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int n;
vector<pair<int, char>> p;
vector<pair<int, char>> pp;

int main() {

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin >> n;
    p.resize(n + 2);
    pp.resize(n + 2);
    int maxa = -1;
    vector<long long> pre(n + 2, 0);
    for(int i = 1; i <= n; ++i) {
        int a;
        char c;
        cin >> a >> c;
        p[i] = {a, c};
        pp[i] = {a, c};
        pre[i] = pre[i - 1] + a;
        maxa = max(maxa, a);
    }

    int l = 1, r = n;
    long long diff = 0;
    while(l <= n && r >= 1) {
        int la = p[l].first;
        int ra = pp[r].first;
        char lc = p[l].second;
        char rc = pp[r].second;
        // cout << la << ' ' << lc << '\n' << ra << ' ' << rc << '\n';
        if(lc == rc) {
            if(la == ra) {
                ++l, --r;
                continue;
            }
            else if(la < ra) {
                pp[r].first -= la;
                ++l;
            }
            else {
                p[l].first -= ra;
                --r;
            }
        }
        else {
            diff += min(ra, la);
            if(la == ra) {
                ++l, --r;
                continue;
            }
            else if(la < ra) {
                pp[r].first -= la;
                ++l;
            }
            else {
                p[l].first -= ra;
                --r;
            }
        }
    }
    // cout << pre[n] << '\n';
    cout << diff / 2 << '\n';
    return 0;
}