#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e8+1000;
int a[maxn],ans = 0;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for(int i = 1; i <= n;i++){
        int b;
        b = a[i];
        if(a[i] <= m){
            a[i] += b;
            m -= b;
            ans ++;
        }
    }
    cout << ans;
    return 0;
}
