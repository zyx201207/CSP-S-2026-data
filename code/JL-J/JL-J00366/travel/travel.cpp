#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    string ac , bc , ax , bx;
    cin >> ac >> ax >> bc >> bx;
    int w = 0 , x = 0 , y = 0 , z = 0 , k = 2;
    while(k){
        w *= 10;
        w += ac[2 - k] - '0';
        y *= 10;
        y += bc[2 - k] - '0';
        x *= 10;
        x += ax[2 - k] - '0';
        z *= 10;
        z += bx[2 - k] - '0';
        k--;
    }
    char a = ax[2] , b = bx[2];
    if(w == y) cout << "1";
    else cout << "0";
    if(w == y && x == z) cout << "1";
    else cout << "0";
    if(((a >= 'A' && a <='C' && b >= 'A' && b <= 'C') || (a >= 'D' && a <='F' && b >= 'D' && b <= 'F')) && w == y && x == z) cout << "1";
    else cout << "0";
    if(((a >= 'A' && a <='C' && b >= 'A' && b <= 'C' && abs(a - b) == 1) || (a >= 'D' && a <='F' && b >= 'D' && b <= 'F')) && w == y && x == z) cout << "1";
    else cout << "0";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
