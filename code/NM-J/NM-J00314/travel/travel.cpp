#include <bits/stdc++.h>

using namespace std;
string a,b,x,y;
int main(){
    freopen ("travel.in","r",stdin);
    freopen ("travel.out","w",stdout);
    cin >> a >> b >> x >>y;
    if (a != x){
        cout << "0000";
    }
    else{
        cout << '1';
        int n = ((b[0] - '0') * 10 + b[1] - '0');
        int m = ((y[0] - '0') * 10 + y[1] - '0');
        if (n != m) cout << "000";
        else {
            cout << '1';
            if ((b[2] == 'C' && y[2] == 'D') || (b[2] == 'D' && y[2] == 'C')) cout << "00";
            else {
            	cout << '1';
                if ((abs(b[2] - y[2]) == 1 ) || ((b[2] == 'D' && y[2] == 'F') || (b[2] == 'F' && y[2] == 'D'))) cout << '1';
                else cout << '0';
            }
        }
    }

	return 0;
}
