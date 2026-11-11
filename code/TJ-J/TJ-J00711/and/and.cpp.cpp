#include<bits/stdc++.h>
long long a[100010];
using namespace std;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cout << a[n] << endl;
    return 0;
}
