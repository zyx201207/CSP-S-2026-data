#include <bits/stdc++.h>
using namespace std;
long long c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        cout << "1";
    }else{
        cout << "0000";
        return 0;
    }
    if(s1[0] == s2[0]&&s1[1] == s2[1]){
        cout << "1";
    }else{
        cout << "000";
        return 0;
    }
    char a = s1[2];
    char b = s2[2];
    if(abs(int(a-b)) <= 2&&a != 'C'&&b != 'D'||a != 'D'&&b != 'C'){
        cout << "1";
    }else{
        cout << "00";
        return 0;
    }
    if(abs(int(a-b)) == 1){
        cout << "1";
    }else{
        cout << "0";
    }
    return 0;
}
