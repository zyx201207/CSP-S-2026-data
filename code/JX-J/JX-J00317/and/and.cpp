#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    cin >> a[1];
    int maxn=a[1];
    long long ans = a[1];
    for(int i = 2; i <= n; i++){
        scanf("%d", &a[i]);
        maxn = max(maxn, a[i]);
        ans = ans & a[i];
    }
    if(m == 1) cout << maxn;
    else if(m == n) cout << ans;
    else if(m == 2){
        int b = 0, maxx=0;
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                int temp = maxx;
                b = a[i]&a[j];
                maxx = max(temp, b);
            }
        }
        cout << maxx;
    }
    return 0;
}
