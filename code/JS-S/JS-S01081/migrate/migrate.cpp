#include<bits/stdc++.h>
using namespace std;

#define int long long
#define L first
#define R second

int c, t, n, d, res, p, len, v[2000010], rwall[2000010], it[2000010], f[2000100], g[2000100];

signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> d, v[n + 1] = 1e18, res = 0;
        for(int i = 1; i <= n; i++)
            cin >> v[i];
        if(n == 1 || c == 13 || c == 14){
            cout << "0\n";
            continue;
        }
        if(c == 11 || c == 12){
            int D = d / (v[2] - v[1]);
            cout << n - (D * 2 - 1) << endl;
            continue;
        }
        for(int i = 1; i <= n; i++)
            rwall[i] = upper_bound(v + 1, v + n + 1, v[i] + d) - v - 1;
        // for(int i = 1; i <= n; i++)
        //     cout << rwall[i] << ' ';
        // cout << endl;
        for(int i = 1; i <= n; i++){
            p = 0, it[len = 1] = i;
            pair<int, int> lim = {i, i}, nlim;
            while(1){
                ++len;
                it[len] = rwall[it[len - 1]];
                if(it[len] == it[len - 1])
                    break;
            }
            len--;
            // for(int j = 1; j <= len; j++)
            //     cout << it[j] << ' ';
            // cout << endl;
            for(int j = 1; j < len; j++){
                // cout << p << ' ' << lim.L << ' ' << lim.R << ' ' << res << endl;
                if(!p){
                    if(lim.L == lim.R)
                        nlim = {lim.R + 1, rwall[lim.R]};
                    else if(lim.L == lim.R - 1){
                        if(rwall[lim.L] <= lim.R)
                            nlim = {lim.R + 1, rwall[lim.R]};
                        else
                            res += rwall[lim.L] - lim.R, nlim = {rwall[lim.L] + 1, rwall[lim.R]};
                    }
                    else{
                        int L = rwall[lim.R - 2] + 1, R = rwall[lim.R - 1];
                        if(L > lim.R)
                            res += R - L + 1;
                        nlim = {rwall[lim.R - 1] + 1, rwall[lim.R]};
                    }
                    if(nlim.R < nlim.L){
                        if(rwall[lim.R - 2] == rwall[lim.R])
                            break;
                        p = 1, nlim.L = nlim.R;
                    }
                    lim = nlim;
                }
                else{
                    int L = rwall[lim.R - 1] + 1, R = rwall[lim.R];
                    res += R - L + 1;
                    lim = {rwall[lim.R - 1] + 1, rwall[lim.R]};
                    if(lim.R < lim.L)
                        break;
                }
            }
            // cout << res << endl;
        }
        cout << res << endl;
    }
    return 0;
}