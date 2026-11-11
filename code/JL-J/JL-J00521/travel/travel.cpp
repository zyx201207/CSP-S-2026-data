#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    for (int i = 0;i <= 1;i++){
        if (c1[i] != c2[i]){
            cout << "0000";
            return 0;
        }
    }
    cout << "1";
    for (int i = 0;i < 2;i++){
        if (s1[i] != s2[i]){
            cout << "000";
            return 0;
        }
    }
    cout << "1";
    char a = s1[2],b = s2[2];
    char x[6] = {'A','B','C','W','D','F'};
    for (int i = 0;i < 5;i++){
        if (a == x[i] && b == x[i+1]){
            cout << "11";
            return 0;
        }else if (b == x[i] && a == x[i+1]){
            cout << "11";
            return 0;
        }else if (a == 'A' && b == 'C'){
            cout << "10";
            return 0;
        }else if (a == 'C' && b == 'A'){
            cout << "10";
            return 0;
        }
    }
    cout << "00";
    return 0;
}
