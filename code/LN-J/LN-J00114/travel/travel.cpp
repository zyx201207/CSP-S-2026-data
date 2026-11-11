#include <bits/stdc++.h>
using namespace std;
string c_one,s_one,c_two,s_two;
char one;
char two;
int same_side(){
    char one1 = s_one[2];
    char two2 = s_two[2];
    cout << one << two;
    if (((one1 >= 'A') && (one1 <= 'C')) && ((two2 >= 'A')&&(two2 <= 'C'))){
        return 1;
    }
    if (((one1 >= 'D') && (one1 <= 'F')) && ((two2 >= 'D')&&(two2 <= 'F'))){
        return 1;
    }
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c_one >> s_one >> c_two >> s_two;
    char one = s_one[2];
    char two = s_two[2];
    if (c_one == c_two){
        cout << 1;
    }
    else{
        cout << "0000\n";
        return 0;
    }
    if ((s_one[0] == s_two[0]) && (s_one[1] == s_two[1])){
        cout << 1;
    }
    else{
        cout << "000\n";
        return 0;
    }
    if (same_side()){
        cout << 1;
    }
    else{
        cout << "00\n";
        return 0;
    }
    if (abs(one-two) == 1){
        cout << 1 << endl;
        return 0;
    }
    else{
        cout << 0 << endl;
        return 0;
    }
    return 0;
}
