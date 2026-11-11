#include <bits/stdc++.h>
using namespace std;
int flag = 0,a = 0,b = 0,a1 = 0,b1 = 0;
char a2 = 'A',b2 = 'A';
int main (){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> a1 >> a2 >> b >> b1 >> b2;
    if (a == b)cout << 1;
    else cout << 0;
    if (a1 == b1) cout << 1;
    else cout << 0;
    if (a == b && a1 == b1 && ((a2 < 'D' && b2 < 'D') || (a2 > 'C' && b2 > 'C'))){
        cout << 1;
        flag = 1;
    }
    else cout << 0;
    if (flag && a == b && a1 == b1 && (((a2 == 'D') && (b2 == 'F')) || (a2 == 'F' && b2 == 'D') || abs((int)(a2 - b2)) == 1)) cout << 1;
    else cout << 0;
    return 0;
}

