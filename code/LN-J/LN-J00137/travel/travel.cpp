#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        cout << 1;
    }
    else{
        cout << 0;
    }
    string p1 = "";
    string p2 = "";
    for(int i = 0;i < s1.size() -1;i++){
        p1 += s1[i];
    }
    for(int i = 0;i < s2.size() - 1;i++){
        p2 += s2[i];
    }
    if(c1 == c2 && p1 == p2){
        cout << 1;
    }
    else{
        cout << 0;
    }
    bool f = 0;
    bool a = s1[s1.size() - 1] <= 'C';
    bool b = s2[s2.size() - 1] <= 'C';

    if(c1 == c2 && p1 == p2 && a == b){
        cout << 1;
        f = 1;
    }
    else{
        cout << 0;
    }
    if(c1 == c2 && p1 == p2 && abs(s1[s1.size() - 1] - s2[s2.size() - 1]) == 1 && f){
        cout << 1;
    }
    else{
        cout << 0;
    }
    return 0;
}
