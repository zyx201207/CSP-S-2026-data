#include<bits/stdc++.h>
using namespace std;
long long n, m, cnt = 1;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    vector<long long> a(n);
    long long x = 0;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        if(a[i] == 0){
            x ++;
        }
    }
    if(x > n - m){
        cout << 0;
        return 0;
    }
    sort(a.rbegin(), a.rend());
    for(int i = 0; i < n - m; i ++){
        long long ans = a[i];
        for(int j = 1; j < m; j ++){
            ans &= a[i + j];
        }
        cnt = max(cnt, ans);
    }
    cout << cnt;
    return 0;
}
/*
5 3
31 3 1 15 7
*/
