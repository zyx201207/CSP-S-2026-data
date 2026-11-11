#include <iostream>
using namespace std;
string a , c , b , d ;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","W",stdout);
    cin >> a >> b >> c >> d ;

    if (a[0] != c[0] || a[1]!= c[1])cout << 0 << 0 << 0 << 0;
    else{
        cout << 1 ;
        if (b[0] != d[0] || b[1] != d[1])cout << 0 << 0 << 0 ;
        else {
            cout << 1 ;
            if ((b[2] <= 'C' && d[2] <= 'C') || (b[2] >= 'D' && d[2] >='D')){
                cout << 1 ;
                if (b[2] >= 'D')cout << 1 ;
                else if (d[2] <= 'C'){
                    if (b[2] == 'B' || d[2] == 'B')cout << 1 ;
                    else cout << 0 ;
                }
                else cout << 0 ;
            }
            else cout << 0 << 0 ;
        }

    }

    fclose(stdin);
    fclose(stdout);
    return 0 ;

}
