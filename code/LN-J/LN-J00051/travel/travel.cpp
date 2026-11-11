#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
int side(string a){
    if(a[2] == 'A' || a[2] == 'B' || a[2] == 'C'){
        return 0;
    }
    return 1;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a0,b0;
    string a1,b1;
    cin >> a0 >> a1 >> b0 >> b1;
    if(a0 == b0){
        cout << 1;
        if(a1[0] == b1[0] && a1[1] == b1[1]){
            cout << 1;
            if(side(a1) == side(b1)){
                cout << 1;
                if(side(a1) == 1){
                    cout << 1;
                }
                else{
                    if(abs(a1[2]-b1[2]) == 1){
                        cout << 1;
                    }
                    else{
                        cout << 0;
                    }
                }
            }
            else{
                cout << 0;
                cout << 0;
            }
        }
        else{
            cout << 0;
            cout << 0;
            cout << 0;
        }

    }
    else{
        cout << 0;
        cout << 0;
        cout << 0;
        cout << 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
