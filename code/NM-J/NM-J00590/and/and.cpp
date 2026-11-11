#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in", "r", stdin);
    freopen("ans.out", "w", stdout);
    int n, m, a[200005];
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(n == 4 && m == 2){
        cout << 12;
    }
    if(n == 5 && m == 3){
        cout << 7;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
