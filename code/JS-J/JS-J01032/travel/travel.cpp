#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    int a1 , a3;
    char b1[3] ,c2[3];
    cin >> a1;
    cin >> b1;
    cin >> a3;
    cin >> c2;
    if(a1 == a3){
        cout << '1';
        if (b1[0] == c2[0] && b1[1] == c2[1]){
            cout << '1';
            if((b1[2] <= 'C' && c2[2] <= 'C') || (b1[2] >= 'D' && c2[2] >= 'D')){
                cout << '1';
                if((b1[2] - c2[2] == 1) || (b1[2] - c2[2] == -1)) {
                    cout << '1';
                }
                else{
                    cout << '0';
                }
            }
            else{
                cout << '0' << '0';
            }
        }
        else{
            cout << '0' << '0' << '0';
        }
    }
    else{
        cout << '0' << '0' << '0' << '0';
    }
    return 0;
}
