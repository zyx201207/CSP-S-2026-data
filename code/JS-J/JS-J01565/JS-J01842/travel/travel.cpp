#include<bits/stdc++.h>
using namespace std;
int f(char c){
    if(c == 'A' || c == 'B' || c == 'C'){
        return 1;
    }else{
        return 2;
    }
}
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a == c){
        cout << 1;
    }else{
        cout << 0;
    }
    string t1 = b.substr(0, 2), t2 = d.substr(0, 2);
    if(a == c && t1 == t2){
        cout << 1;
    }else{
        cout << 0;
    }
    char c1 = b[b.size() - 1], c2 = d[d.size() - 1];
    if(a == c && t1 == t2 && f(c1) == f(c2)){
        cout << 1;
    }else{
        cout << 0;
    }
    if(a == c && t1 == t2 && f(c1) == f(c2) && (c1 == 'A' && c2 == 'B') || (c1 == 'B' && c2 == 'C') || (c1 == 'D' && c2 == 'F')){
        cout << 1;
    }else{
        cout << 0;
    }
    return 0;
}
