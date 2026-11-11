#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e6 + 3;
int c, t, n, d, x[N], ans, idx;
vector<vector<int>> v;
int check(int p, int st, int ed){
    int sz = ed;
    bool f = false;
    queue<int> q;
    q.push(st);
    while(!q.empty()){
        int i = q.front();
        q.pop();
        int mxj = i + 1, j;
        for(j = i + 2; j < sz; j++){
            if(v[p][j] - v[p][i] <= d){
                mxj = j;
            }
        }
        q.push(mxj);
        if(mxj == j + 1){
            continue;
        }
        int mnj = mxj - 1;
        if(v[p][mxj + 1] - v[p][mnj] <= d){
            f = true;
        }
        q.push(mnj);
        if(mnj == j + 1){
            continue;
        }
        int mnnj = mnj - 1;
        if(v[p][mxj + 1] - v[p][mnj] <= d){
            f = false;
            return f;
        }
    }
    return f;
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    if(c == 11 || c == 12){
        while(t--){
            ans = 0;
            cin >> n >> d;
            if(n == 1 || n == 2){
                cout << "0\n";
                continue;
            }
            int q, tms;
            for(int i = 0; i < n; i++){
                cin >> x[i];
            }
            q = x[2] - x[1];
            if(d < q){
                cout << "0\n";
                continue;
            }
            tms = d / q;
            if(tms == 1){
                cout << "0\n";
                continue;
            }
            for(int i = n - 1; i >= 3; i--){
                if(i % tms == tms - 1){
                    ans += n - i;
                }
            }
            cout << ans << '\n';
        }
        return 0;
    }
    while(t--){
        cin >> n >> d;
        if(n == 1 || n == 2){
            cout << "0\n";
            continue;
        }
        bool fa = true;
        cin >> x[0];
        for(int i = 1; i < n; i++){
            cin >> x[i];
            v[idx].push_back(x[i]);
            if(x[i] - x[i - 1] <= d){
                fa = false;
            }else{
                idx++;
            }
        }
        if(fa){
            cout << "0\n";
            continue;
        }
        for(int i = 0; i < idx; i++){
            for(int st = 0; st < v[i].size(); st++){
                for(int ed = st + 3; ed < v[i].size(); ed++){
                    if(ed < v[i].size()){
                        ans += check(i, st, ed);
                    }
                }
            }
        }
        cout << ans;
    }
    return 0;
}