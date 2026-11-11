#include <bits/stdc++.h>
using namespace std;
int c11, c22;
char s11[7], s22[7];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c11;
    for (int i = 1;i <= 3;i++){
        cin >> s11[i];
    }
    cin >> c22;
    for (int i = 1;i <= 3;i++){
        cin >> s22[i];
    }
    if (c11 == c22){
        cout << 1;
    }
    else{
        cout << 0 << 0 << 0 << 0;
        return 0;
    }
    bool b = 1;
    for (int i = 1;i <= 2;i++){
        if (s11[i] != s22[i]){
            b = 0;
            break;
        }
    }
    if (b == 1){
        cout << 1;
        if (s11[3] == 'F' && s22[3] == 'E'){
            cout << 1;
            cout << 1;
            return 0;
        }
        else if(s11[3] == 'E' && s22[3] == 'F'){
            cout << 1;
            cout << 1;
            return 0;
        }
        else if (s11[3] == 'A'){
            if(s22[3] == 'B'){
                cout << 1;
                cout << 1;
                return 0;
            }
            else if(s22[3] == 'C'){
                cout << 1;
                cout << 0;
                return 0;
            }
            else{
                cout << 0;
                cout << 0;
                return 0;
            }
        }
         else if (s11[3] == 'B'){
            if(s22[3] == 'A'){
                cout << 1;
                cout << 1;
                return 0;
            }
            else if(s22[3] == 'C'){
                cout << 1;
                cout << 0;
                return 0;
            }
            else{
                cout << 0;
                cout << 0;
                return 0;
            }
        }
         else if (s11[3] == 'C'){
            if(s22[3] == 'B'){
                cout << 1;
                cout << 1;
                return 0;
            }
            else if(s22[3] == 'A'){
                cout << 1;
                cout << 0;
                return 0;
            }
            else{
                cout << 0;
                cout << 0;
                return 0;
            }
        }
        else{
            cout << 0;
            cout << 0;
            return 0;
        }
    }
    else{
        cout << 0;
        cout << 0;
        cout << 0;
    }
    return 0;
}
