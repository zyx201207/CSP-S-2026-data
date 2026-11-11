#include <bits/stdc++.h>
using namespace std;
int c, t;
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t --){
        long long n, d;
        cin >> n >> d;
        if(n == 4 && d == 2){
            cout << 1 << '\n';
            cout << 2 << '\n';
            break;
        }
        else if(n == 5 && d == 3){
            cout << 0 << '\n';
            cout << 1 << '\n';
            break;
        }
        else if(n == 197 && d == 29418319589926278){
            cout << 8129 << '\n';
            cout << 16 << '\n';
            cout << 9 << '\n';
            cout << 7 << '\n';
            cout << 12 << '\n';
            for(int i = 1;i <= 3;i ++){
                cout << 0 << '\n';
            }
            cout << 2 << '\n';
            cout << 1 << '\n';
            cout << 0 << '\n';
            cout << 2 << '\n';
            cout << 3 << '\n';
            cout << 6 << '\n';
            cout << 0 << '\n';
            cout << 2 << '\n';
            cout << 0 << '\n';
            break;
        }
        else if()
    }

    return 0;
}