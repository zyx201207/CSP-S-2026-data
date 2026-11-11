#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[500010], b[500010];
ll cnts[500010];
stack<int> s;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        ll cntt[500010] = {0};
        for(int j = i; j <= n; j++){
            if(cntt[a[j]]){
                for(int k = j - 1; a[k] != a[j]; k--){
                    if(cntt[a[k]] == 0)
                        continue;
                    cntt[a[k]]--;
                }
                cntt[a[j]]--;
            }
            cntt[a[j]]++;
        }
        for(int j = 1; j <= m; j++)
            cnts[j] += cntt[j];
    }
    for(int i = 1; i <= m; i++)
        cout << cnts[i] << ' ';

    return 0;
}
