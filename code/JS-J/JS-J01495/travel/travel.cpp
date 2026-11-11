#include <iostream>

using namespace std;
string a, a1, b, b1;

void init(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a >> a1 >> b >> b1;
}

void solve(){
    if(a != b){
        cout << 0 << 0 << 0 << 0 << endl;
        return;
    } else {
        cout << 1;
        if(a1[0] != b1[0] || a1[1] != b1[1]){
            cout << 0 << 0 << 0;
            return;
        } else {
            cout << 1;
            for(char i = 'A'; i <= 'C'; ++i){
                for(char j = 'A'; j <= 'C'; ++j){
                    if(i == a1[2] && j == b1[2]){
                        cout << 1;
                        if(i == j + 1 || i == j - 1){
                            cout << 1;
                            return;
                        } else {
                            cout << 0;
                            return;
                        }
                    }
                }
            }
            if(a1[2] == 'D' && b1[2] == 'F' || a1[2] == 'F' && b1[2] == 'D')
                cout << 1 << 1;
            else
                cout << 0 << 0;
        }
    }
    cout << endl;
}

int main(){
    init();
    solve();
    return 0;
}
