#include<bits/stdc++.h>
using namespace std;
int n, m;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    for(int i = 1; i <= m; i ++){
        cout << i << " ";
    }
    return 0;
}
