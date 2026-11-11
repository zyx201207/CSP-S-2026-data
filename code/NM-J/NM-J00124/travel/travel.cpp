#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int a, c;
    string b, d;
    cin >> a >> b;
    cin >> c >> d;
    if(a == c){
        cout << 1;
        if(b[0] == d[0] && b[1] == d[1]){
            cout << 1;
            if((b[2] <= 'C' && d[2] <= 'C')|| (b[2] >= 'D' && d[2] >= 'D')){
                cout << 1;
                if(b[2] <= 'C' && d[2] <= 'C'){
                    if(b[2] - d[2] == 1 || b[2] - d[2] == -1){
                        cout << 1;
                    }
                }else if(b[2] >= 'D' && d[2] >= 'D'){
                    if(b[2] - d[2] == 2 || b[2] - d[2] == -2){
                        cout << 1;
                    }else cout << 0;
                }
            }else cout << 0 << 0;
        }else cout << 0 << 0 << 0;
    }else cout << 0 << 0 << 0 << 0;
    return 0;
}
