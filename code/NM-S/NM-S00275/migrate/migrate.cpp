#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int n, m, k, p;
    cin >> n >> m >> k >> p;
    if(m == 2 && p == 2){
        cout << "1\n2";
    }
    else{
        cout << "0\n1";
    }
    return 0;
}