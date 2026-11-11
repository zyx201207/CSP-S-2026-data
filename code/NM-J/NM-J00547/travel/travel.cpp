#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int cnt = -1;
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2){
        cout << 1;
    }
    else cout << 0000;
    for (int i = 0;i<2;i++){
        if (s1[i] == s2[i]){
            cnt++;
        }
    }
    if (cnt == 1){
        cout << 1;
        if (s1[2] == 'A'){
            if (s2[2] == 'B'){
                cout << 11;
            }
            else if (s2[2] == 'C'){
                cout << 10;
            }
            else cout << 0 << 0;
        }
        if (s1[2] == 'B'){
            if (s2[2] == 'A'){
                cout <<11;
            }
            else if (s2[2] == 'C'){
                cout << 11;
            }
            else cout << 0 << 0;
        }
        if (s1[2] == 'C'){
            if (s2[2] == 'A'){
                cout << 10;
            }
            else if (s2[2] == 'B'){
                cout << 11;
            }
            else cout << 0 << 0;
        }
        if (s1[2] == 'D'){
            if (s2[2] == 'E'){
                cout <<11;
            }
            else cout << 0 << 0;
        }
        if (s1[2] == 'E'){
            if (s2[2] == 'D'){
                cout <<11;
            }
            else cout << 0 << 0;
        }
    }
    else cout << 0 << 0 << 0;
    return 0;
}
