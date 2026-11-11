#include <iostream>
#include <algorithm>
using namespace std;
int a[200001], n, m, ans;
void dfs(int num, int np, int s){
    if (num == m){
        ans = max(ans, s);
        return;
    }
    for (int i = np;i <= n;i++)
        dfs(num + 1, i + 1, s ? s & a[i] : a[i]);
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        cin >> a[i];
    dfs(0, 1, 0);
    cout << ans;
    return 0;
}
