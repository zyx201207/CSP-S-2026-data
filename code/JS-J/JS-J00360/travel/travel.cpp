#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 1e6 + 10;
typedef long long ll;
typedef pair<int,int> PII;
//vector<vector<int>> adj;


void solve() {
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    string ans = "0000";
    if(c1 == c2) {
        ans[0] = '1';
        int a = (s1[0] - '0') * 10 + s1[1] - '0';
        int b = (s2[0] - '0') * 10 + s2[1] - '0';
        if(a == b) {
            ans[1] = '1';
            int c = s1[2] - 'A' + 1;
            int d = s2[2] - 'A' + 1;
            if(c > d) swap(c, d);
            if(d <= 3) {
                ans[2] = '1';
                if(d - c == 1) ans[3] = '1';
            } else if(c >= 4) {
                ans[2] = ans[3] = '1';
            }
        }
    }
    cout << ans;

}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
