#include <bits/stdc++.h>
using namespace std;

struct node {
    int a;
    int x;
};
const int N = 5e5+5, M = 3e5+5;
int n, m;
int a[N];
int ans[M];

void mo(int b) {
    vector<int>moz;
    map<int, node>mp;
    int z = -1;
    //cout << b << ":" << endl;
    for (int i = b; i <= n; i++) {
        int ai = a[i];
        if (mp[ai].a == 1) {
            for (z; z > mp[ai].x;) {
                //cout << "pop:" << moz[z] << " " << mp[moz[z]].x << endl;
                mp[moz[z]] = {0, 0};
                moz.pop_back();
                z--;
                //cout << z << endl;
            }
            //for (int i = 0; i <= z; i++) {
            //    cout << moz[i] << " ";
            //}
        } else {
            while ((moz.begin() + z + 1) != moz.end() && moz[z] != 0) {
                z++;
                //cout << z << endl;
            }
            ++z;
            mp[a[i]] = {1, z};
            moz.push_back(0);
            moz[z] = a[i];
            //cout << z << endl;
            //cout << "push:" << moz[z] << " " << mp[moz[z]].x << endl;
        }
    }
    for (int i = 0; i <= z; i++) {
        //cout << moz[i] << " ";
        ans[moz[i]]++;
    }
    //cout << endl;
}

void solve() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; i++) {
        mo(i);
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
}

int main() {
    int ac = 1;
    // cin >> ac;
    while(ac--) {
        solve();
    }
}
