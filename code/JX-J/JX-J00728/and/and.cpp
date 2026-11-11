#include<bits/stdc++.h>
using namespace std;

bool cmp(int x, int y){
    return x > y;
}

long long n, m, a[400000], ans, maxx;

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }


    sort(a, a + n, cmp);


    for(int i = 0; i < n - m; i ++){
        ans = a[i];
        for(int j = 0; j < m - 1; j++){
            ans = ans & a[i + j + 1];
        }
        maxx = max(maxx, ans);
    }
    cout << maxx;
    return 0;
}
