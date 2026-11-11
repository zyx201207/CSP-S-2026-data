#include <bits/stdc++.h>
using namespace std;
string c_1, s_1, c_2, s_2;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c_1 >> s_1 >> c_2 >> s_2;
    if(c_1 == c_2){
        cout << 1;
    }
    else cout << 0;
    int tmp1 = (s_1[0] - '0') * 10 + s_1[1] - '0';
    int tmp2 = (s_2[0] - '0') * 10 + s_2[1] - '0';
    if(c_1 == c_2 && tmp1 == tmp2){
        cout << 1;
    }
    else cout << 0;

    bool bo = false;
    if(s_1[2] <= 'C' && s_2[2] <= 'C')bo = true;
    if('C' < s_1[2] && 'C' < s_2[2])bo = true;
    if(c_1 == c_2 && tmp1 == tmp2 && bo == true){
        cout << 1;
    }
    else cout << 0;
    if(c_1 == c_2 && tmp1 == tmp2 && bo == true && abs(s_2[2] - s_1[2]) == 1){
        cout << 1;
    }
    else cout << 0;
    return 0;
}
