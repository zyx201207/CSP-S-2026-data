#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int a, b, c, d;
    char x, y;
    cin >> a >> c >> x >> b >> d >> y;
    int x1 = (int)(x - 'A') + 1;
    int x2 = (int)(y - 'A') + 1;
    if(a == b){
        cout << 1;
        if(c == d){
            cout << 1;
            if(x1 <= 3 && x2 <= 3 || x1 >= 4 && x2 >= 4){
                cout << 1;
                if(x1 >= 4 && x2 >= 4){
                    cout << 1;
                }else if(x1 == 1 && x2 == 3 || x1 == 3 && x2 == 1){
                    cout << 0;
                }else{
                    cout << 1;
                }
            }else{
                cout << 0;
                cout << 0;
            }
        }else{
            cout << 0;
            cout << 0;
            cout << 0;
        }
    }else{
        cout << 0;
        cout << 0;
        cout << 0;
        cout << 0;
        cout << 0;
    }
    return 0;
}
//02 01A 02 01B
