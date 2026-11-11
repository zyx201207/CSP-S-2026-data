#include <iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1,s1,c2,s2;
    if (c1 == c2){
        cout << 1;
    }
    else {
        cout << 0;
    }
    if (s2 /10 == c2 / 10){
        cout << 1;
    }
    else {
        cout << 0;
    }
    if (s2 % 10 == D && c2 % 10 ==F || s2 % 10 == F && c2 % 10 == F){
        cout << 1
    }
    else {
        cout << 0;
    }
    cout << 0;
    return 0;
}
