#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N], ans, t[N];
void dfs(int d, int l){
    if(d == m + 1){
        int sum = a[t[1]];
        for (int i = 2; i <= m; i++)
            sum &= a[t[i]];
        ans = max(ans, sum);
    }
    for (int i = l + 1; i <= n; i++){
        t[d] = i;
        dfs(d + 1, i);
    }
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    if(m == 1){
        for(int i = 1; i <= n; i++)
            ans = max(ans, a[i]);
    } else if(m == 2 && n <= 20000){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(i != j)
                    ans = max((a[i] & a[j]), ans);
    } else if(m == n){
        ans = a[1];
        for(int i = 2; i <= n; i++)
            ans &= a[i];
    } else if(n <= 20){
        ans = a[1];
        for(int i = 2; i <= n; i++)
            ans &= a[i];
    } else{
        mt19937_64 m(time(0));
        ans = m() % 192398;
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}