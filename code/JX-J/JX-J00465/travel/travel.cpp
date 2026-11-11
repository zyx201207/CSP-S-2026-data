#include<bits/stdc++.h>
using namespace std;
bool P(char s){
    if(s == 'A' || s == 'B' || s == 'C') return 1;
    return 0;
}
bool check(char s1, char s2){
    if(s1 > s2) swap(s1,s2);
    if((s1 == 'A' && s2 == 'B')||(s1 == 'B' && s2 == 'C')||(s1 == 'D' && s2 == 'F')){
        return true;
    }
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a != c){
        cout << "0000";
        return 0;
    }else{
        cout << 1;
        char s1 = b[2], s2 = d[2];
        b.pop_back();
        d.pop_back();
        if(b == d){
            cout << 1;
            if(P(s1) == P(s2)){
                cout << 1;
                if(check(s1,s2)){
                    cout << 1;
                }else{
                    cout << 0;
                }
            }else{
                cout << "00";
            }
        }else{
            cout << "000";
        }
    }
    return 0;
}
