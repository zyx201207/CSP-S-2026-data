#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m; cin >> n >> m;
    long long maxx = -1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    if(m == 1){
        cout << maxx;
        return 0;
    }
    maxx = -1;
    if(m == 2){
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                maxx = max(maxx, (a[i] & a[j]));
            }
        }
        cout << maxx;
        return 0;
    }
    long long cnt = a[1];
    if(m == n){
        for(int i = 2; i <= n; i++){
            cnt &= a[i];
        }
        cout << cnt;
        return 0;
    }
    if(m == n - 1){
        for(int j = 2; j <= n; j++){
            for(int i = 2; i <= n; i++){
                if(i == j) continue;
                cnt &= a[i];
            }
            maxx = max(maxx, cnt);
            cnt = a[1];
        }
        cnt = a[2];
        for(int i = 3; i <= n; i++){
            cnt &= a[i];
        }
        maxx = max(maxx, cnt);
        cout << maxx;
        return 0;
    }
    return 0;
}
