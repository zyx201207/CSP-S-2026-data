#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    long long n, m;
    cin >> n >> m;

    vector<long long> v(n + 5);
    vector<long long> sum(n + 5, 0);
    bool flag = true;

    for (long long i = 1; i <= n; i++) {
        cin >> v[i];
    }

    long long l = 1, r = 1;
    long long mx = -1;
    sort(v.begin() + 1, v.begin() + n + 1);

    for (long long i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + v[i];
    }

    for (r = 1; r <= n; r++) {
        
        long long need = (r - l + 1) * v[r] - sum[r] + sum[l - 1];

        // if (r == 5 && l == 3) {
        //    cout << "!!!!!!" << need << '\n';
        // }

        while (need > m) {
            l++;
            need = (r - l + 1) * v[r] - sum[r] + sum[l - 1];
        }
        // cout << l << ' ' << r << " " << need << " " << sum[r] - sum[l - 1] << '\n';

        mx = max(mx, r - l + 1);
    }

    cout << mx;
    
    return 0;
}

/*

g++ crystal.cpp -o crystal -g -O2 -Wall 
./crystal

*/