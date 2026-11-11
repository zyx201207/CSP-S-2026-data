#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    char a = s1[2],b = s2[2];
    if(c1 == c2){
        cout << 1;
    }else{
        cout << "0000";
        return 0;
    }
    if(s1[1] == s2[1] && s1[0] == s2[0]){
        cout << 1;
    }else{
        cout << "000";
        return 0;
    }
    bool f;
    if(b>a)swap(a,b);
    if(a == 'E' && b == 'D'){
        cout << "11";
        f = 1;
    }
    if(a == 'C' && b == 'B'){
        cout << "11";
        f = 1;
    }
    if(a == 'C' && b == 'A'){
        cout << "10";
        f = 1;
    }
    if(a == 'B' && b == 'A'){
        cout << "11";
        f = 1;
    }
    if(!f) cout << "00";
    return 0;
}

