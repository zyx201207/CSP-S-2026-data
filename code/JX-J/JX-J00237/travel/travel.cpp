#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s1, c1, s2, c2;
    cin >> s1 >> c1 >> s2 >> c2;
    if(s1 == s2){
        cout << 1;
        if(c1[0] == c2[0] && c1[1] == c2[1]){
            cout << 1;
            if(c1[2] <= 'C' && c2[2] <= 'C'){
                cout << 1;
                if(c1[2] - c2[2]== -1 || c1[2] - c2[2] == 1){
                    cout << 1;
                }else{
                    cout << 0;
                }
            }else if(c1[2] > 'C' && c2[2] > 'C'){
                cout << 1 << 1;
            }else{
                cout << 0 << 0;
            }
        }else{
            cout << 0 << 0 << 0;
        }
    }else{
        cout << 0 << 0 << 0 << 0;
    }
    return 0;
}
