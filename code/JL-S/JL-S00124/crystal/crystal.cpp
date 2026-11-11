#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a[100010];
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1, a+n+1);
    int j = 1, ans = 0;
    for(int i=1;i<=m;i++){
        a[j] += 1;
        if(a[j] == a[j+1]){
                j++;
                ans++;
        }
    }
    cout << ans;
    return 0;
}
