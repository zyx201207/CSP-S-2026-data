#include <bits/stdc++.h>
using namespace std;
long long n,m,ans[300030],x[500050],t[300030],ne[500050];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> x[i];
        if (t[x[i]] != 0) {ne[t[x[i]]] = i;t[x[i]] = i;}
        else t[x[i]] = i;
    }
    ans[x[n]] = 1;
    for (int i = 1;i < n;i++){
        vector <int> tt;
        for (int j = i;j <= n;j++){
            tt.push_back(j);
            while (ne[j] != 0) j = ne[j];
        }
        for (auto v : tt) ans[x[v]]++;
    }
    for (int i = 1;i <= m;i++) cout << ans[i] << " ";
    return 0;
}
