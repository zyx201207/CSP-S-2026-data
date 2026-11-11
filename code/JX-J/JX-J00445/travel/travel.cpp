#include <bits/stdc++.h>
using namespace std;


int n[7];

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        n[0] = 1;
        if(s1[0] == s2[0] && s1[1] == s2[1]){
            n[1] = 1;
            if(s1[2] < 'D' && s2[2] < 'D'){
                n[2] = 1;
                if(s1[2] + 2 != s2[2] || s2[2] + 2 != s1[2]){
                    n[3] = 1;
                }
            }
            else if(s1[2] > 'C' && s2[2] > 'C'){
                n[2] = 1;
                n[3] = 1;
            }
        }
    }
    for(int i = 0;i < 4;i++){
        cout << n[i];
    }
}
