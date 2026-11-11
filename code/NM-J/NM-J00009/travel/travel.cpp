#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
bool flag1 = true;
bool flag2 = true;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a >> b >> c >> d;
    for(int i = 0;i<2;i++){
        if(a[i]==c[i]) continue;
        else flag1 = false;
    }
    if(flag1){
        cout << 1;
        for(int i = 0;i < 2;i++){
            if(b[i]==d[i]) continue;
            else{
                flag2 = false;
                break;
            }
        }
        if(flag2){
            cout << 1;
            if(b[2]<='C'&&d[2]<='C'||b[2] >= 'D'&&d[2]>='D'){
                cout << 1;
                if(b[2]+1==d[2]||b[2]-1==d[2]) cout << 1;
                else cout << 0;
            }
            else cout << 0;
        }
        else{
            cout << 0 << 0 << 0;
        }
    }
    else{
        cout << 0 << 0 << 0 << 0;
        return 0;
    }
    return 0;
}
