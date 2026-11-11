#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<int> a{0};


    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;

//        if (i == 1 || t != a[i - 1]) {
            a.push_back(t);
//        }
    }
//    n = a.size() - 1;

    vector<int> cnt(m + 5, false);

    for (int i = 1; i <= n; i++) {

        vector<int> v(m + 5, 0);//shifouhaizai
        vector<int> d;//paidui

        for (int j = i; j <= n; j++) {
            if (v[a[j]] == 0) {
                d.push_back(a[j]);
                v[a[j]]++;
            } else {
                while (d[d.size() - 1] != a[j] && d.size() > 0) {
                    v[d[d.size() - 1]]--;
                    d.pop_back();
                }
                
            }
        } 
        
        

        for (auto i : d) {
            cnt[i]++;
        }

    }

    for (int i = 1; i <= m; i++) {
        cout << cnt[i] << ' ';
    }
    
    return 0;
}

/*n                                                                       
g++ card.cpp -o card -Wall -O2 -g 
time ./card

*/
