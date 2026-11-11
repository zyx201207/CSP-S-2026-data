#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >>c1>>s1>>c2>>s2;
    bool same=false;
    bool same_p = false;
    bool same_c = false;
    if (c1==c2){
        cout<<1;
        same=true;
    } else {
        cout << 0;
    }
    if (same && s1[0]==s2[0] && s1[1]==s2[1]){
        same_p=true;
        cout << 1;
    } else {
        cout << 0;
    }
    if (same && same_p){
        same_c = true;
        if (s1[2]-'A'<=2 && s2[2]-'A'<=2){
            cout <<1;
        }else if (s1[2]-'A'>=3 && s2[2]-'A'>=3){
            cout << 1;
        }else {
            cout << 0;
            same_c = false;
        }
    } else {
        cout << 0;
    }
    if (same && same_p && same_c){
        if (s1[2]-'A'>=3){
            cout << 1;
        } else {
            if (abs((s1[2]-'A')-(s2[2]-'A'))==1){
                cout << 1;
            } else {
                cout << 0;
            }
        }
    } else {
        cout << 0;
    }
    return 0;
}
