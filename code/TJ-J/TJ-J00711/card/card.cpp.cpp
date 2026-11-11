#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cout << m << " " << a[1] << " " << n << endl;
    return 0;
}
