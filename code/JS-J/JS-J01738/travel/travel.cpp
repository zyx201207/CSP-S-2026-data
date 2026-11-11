#include<bits/stdc++.h>
using namespace std;
string s1, s2, c1, c2;
int n1 = 0, n2 = 1, n3 = 0, n4 = 0;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> s1 >> c1 >> s2 >> c2;
    if(s1 != s2){
        cout <<"0000";
        return 0;
    }
    else n1 = 1;
    for(int i = 0; i < 2; i++){
        if(c1[i] != c2[i]){
            cout << "1000";
            return 0;
        }
    }
    if((c1[2] == 'D' || c1[2] == 'F') && (c2[2] == 'D' || c2[2] == 'F')) n3 = 1, n4 = 1;
    if((c1[2] >= 'A' && c1[2] <= 'C') && (c2[2] >= 'A' && c2[2] <= 'C')) n3 = 1;
    if((c1[2] == 'A' && c2[2] == 'B') || (c1[2] == 'B' && c2[2] == 'C')) n4 = 1;
    cout << n1 << n2 << n3 << n4;
    return 0;
    /*zhe jiu shi kao qian bu fu xi de xia chang ma
    lian zen me tiao shi shu ru yang li dou bu zhi dao
    ru guo you lai sheng wo jue dui bu hui xuan xin ao le
    bye bye CCF*/
}
