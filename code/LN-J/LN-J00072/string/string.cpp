#include <bits/stdc++.h>

using namespace std;

int main () {
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int a;
    char c , fro_c;
    deque<pair<unsigned long long , char> > q;
    for (int i = 1; i <= n; i ++) {
        cin >> a >> c;
        if (i == 1) {
            fro_c = c;
            q.push_back({a , c});
        } else {
            if (c == fro_c) {
                q.back().first += a;
            } else {
                q.push_back({a , c});
                fro_c = c;
            }
        }
    }


    int i = 0 , j = q.size() - 1;
    unsigned long long sum = 0;
    while (i < j) {
        auto [u1 , v1] = q[i];
        auto [u2 , v2] = q[j];
        if (v1 != v2) {
            if (u1 > u2) {
                q[i].first -= u2;
                j --;
                sum += u2;
            } else if (u1 < u2){
                q[j].first -= u1;
                i ++;
                sum += u1;
            } else {
                i ++;
                j --;
                sum += u1;
            }
        } else {
            if (u1 > u2) {
                q[i].first -= u2;
                j --;
            } else if (u1 < u2) {
                q[j].first -= u1;
                i ++;
            }
        }
    }
    cout << sum;
    return 0;
}
