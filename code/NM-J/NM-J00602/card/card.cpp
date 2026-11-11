#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int a[N], s[M];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] != a[i - 1]){
            s[a[i - 1]] = i - 1;
        }
    }
    s[a[n]] = n;
    for(int i = 1;i <= m;i++){
        cout << s[i] << " ";
    }
    return 0;
}
