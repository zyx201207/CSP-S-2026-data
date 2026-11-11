#include<bits/stdc++.h>
using namespace std;
int a[200001];
bitset<30> b[200001];
int main() {

    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> vec;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
        vec.push_back(i);
    }
    for(int i = 29; i >= 0; i--) {
        if(i < 0) break;
        int cnt = 0;
        for(int k : vec) {
            if(b[k][i] == 1)
                cnt++;
            if(cnt >= m) break;
        }
        if(cnt >= m) {
            ans += (1 << i);
            vector<int> vec2;
            for(int k : vec)
                if(b[k][i])
                    vec2.push_back(k);
            vec = vec2;
        }
    }
    cout << ans;
    return 0;
}
