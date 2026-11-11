#include<bits/stdc++.h>
using namespace std;
string c1, c2, c3, c4;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> c1 >> c2 >> c3 >> c4;
    if(c1 != c3){
        cout << "0000\n";
        return 0;
    }else{
        cout << "1";
    }
    int a = (c2[0] - '0') * 10 + (c2[1] - '0');
    int b = (c4[0] - '0') * 10 + (c4[1] - '0');
    if(a != b){
        cout << "000\n";
        return 0;
    }else{
        cout << "1";
    }
    if((c2[2] <= 'C' && c4[2] > 'C') || c2[2] > 'C' && c4[2] <= 'C'){
        cout << "00\n";
        return 0;
    }else{
        cout << "1";
    }
    if((c2[2] == 'A' && c4[2] == 'B') || (c2[2] == 'B' && c4[2] == 'C') || c2[2] == 'D' && c4[2] == 'F'){
        cout << "1\n";
    }else{
        cout << "0\n";
    }
    return 0;
}