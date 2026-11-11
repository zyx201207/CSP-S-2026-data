#include <bits/stdc++.h>
using namespace std;
int main(){
    string c1, s1, c2, s2;
    freopen("travel.in",'r',stdin);
    freopen("travel.out",'w',stdout);
    cin >> c1 >> s1 >> c2 >> s2;

    if (c1 != c2){
        cout << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0;
        return 0;
    }

    for (int i = 0;i < 2;i++)
        if (s1[i] != s2[i]){
            cout << 1 << ' ' << 0 << ' ' << 0 << ' ' << 0;
            return 0;
        }

    if (s1[2] > 'C' && s2[2] < 'D' || s2[2] > 'C' && s1[2] < 'D'){
        cout << 1 << ' ' << 1 << ' ' << 0 << ' ' << 0;
        return 0;
    }

    if (s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2] || s1[2] == 'D' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'D'){
        cout << 1 << ' ' << 1 << ' ' << 1 << ' ' << 1;
    }
    else{
        cout << 1 << ' ' << 1 << ' ' << 1 << ' ' << 0;
    }
    return 0;
}
