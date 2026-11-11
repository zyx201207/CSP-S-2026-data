#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 3e5 + 10;
int n, m, a[N], f[M], k[M], v[N], ans[M];
void solve(int s){
    for(int i = 1; i <= m; i++)
        f[i] = k[i] = v[M] = 0;
    for(int i = s; i <= n; i++){
        if(f[a[i]]){
            for(int j = f[a[i]]; j < i; j++)
                if(v[j] == 0)
                    k[a[j]]--, v[j] = 1;
            f[a[i]] = i;
        }
        k[a[i]]++;
        if(f[a[i]] == 0)
            f[a[i]] = i;
    }
    for (int i = 1; i <= m; i++)
        if(k[i] > 0)
            ans[i]++;
}
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        solve(i);
    for(int i = 1; i <= m; i++)
        cout << ans[i] << " ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}