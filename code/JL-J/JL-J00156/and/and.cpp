#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int cnt = 0;
    for(int j = 0; j <= n; j++){
        cnt += a[j];
    }
    int ans = 0;
    ans = cnt / n;
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
