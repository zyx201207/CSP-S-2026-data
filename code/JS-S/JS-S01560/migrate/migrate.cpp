
#include <bits/stdc++.h>
using namespace std;
vector<long long> x;
long long n, d;

int cnt = 0;
int mn = INT_MAX;

void dfs(int no, int e, int c) {
    if (no == e) {
        mn = min(mn, c);
        return;
    }

    for (int i = no + 1; i <= n; i++) {
        if (x[i] - x[no] <= d) {
            dfs(i, e, c + 1);
        } else {
            break;
        }
    }
}

void dfs2(int no, int e, int c, int mn) {
    if (no == e) {
        if (c == mn) {
            cnt++;
        }
        return;
    }

    for (int i = no + 1; i <= n; i++) {
        if (x[i] - x[no] <= d) {
            dfs2(i, e, c + 1, mn);
        } else {
            break;
        }
    }

}


int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    
    int c, t;
    cin >> c >> t;

    while(t--) {
        
        cin >> n >> d;
        
        x.resize(n + 5);

        for (int i = 1; i <= n; i++) {
            cin >> x[i];
        }

        int ccnt = 0;

         for (int u = 1; u <= n; u++) {
             for (int v = u + 1; v <= n; v++) {
                mn = INT_MAX;
                cnt = 0;
                dfs(u, v, 0);
                dfs2(u, v, 0, mn);
                if (cnt == 2) ccnt++;

                    
                
             }
         }

        cout << ccnt << '\n';
    }
    
    return 0;
}

/*

g++ migrate.cpp -o migrate -g -O2 -Wall 
./migrate

*/