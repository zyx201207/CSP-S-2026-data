#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int c1, s1, c2, s2;
    int a = 0, b = 0, c = 0, d = 0;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        a = a + 1;
    }
    for(int i = '0'; i <= '9'; i++){
        if(s1 == s2){
            b = b + 1;
        }
    }
    for(int i = '0'; i <= '9'; i++){
        if(s1 == s2){
            c = c + 1;
        }
    }
    cout << a << b << c << d << endl;
    return 0;
}
