#include<bits/stdc++.h>
using namespace std;
string a, b, c, d;
int x, y;
int main(){
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   cin >> a;
   scanf("%2d", &x);
   cin >> b;
   cin >> c;
   scanf("%2d", &y);
   cin >> d;
   if (a == c) {
        cout << 1;
        if(x == y){
            cout << 1;
            if (b == "A" && d == "B" || b == "A" && d == "C"|| b == "B" && d == "A"|| b == "B" && d == "C"|| b == "C" && d == "A"|| b == "C" && d == "B"|| b == "F" && d == "D"|| b == "D" && d == "F"){
                cout << 1;
                if(b == "A" && d == "B" ||b == "B" && d == "A" ||b == "B" && d == "C" ||b == "C" && d == "B" ||b == "D" && d == "F" ||b == "F" && d == "D" ){
                    cout << 1;
                }
                else cout << 0;
            }
            else cout << "00";
        }
        else cout << "000";

   }
   else cout << "0000";

    return 0;
}
