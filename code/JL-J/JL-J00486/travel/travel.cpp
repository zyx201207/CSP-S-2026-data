#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,c;
    string b,d;
    cin >> a >> b >>c >> d;
    if(a==c){
        cout << 1;
        if(b[1]==d[1]&&b!=d){
            cout <<1;
              if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
                cout << 11;
                return 0;
            }
            else if((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A')){
                cout << 10;
                return 0;
            }
            else {
                cout << 11;
                return 0;
            }
        }
        else{
            cout <<000;
            return 0;
        }
    }
    else{
        cout << 0000;
        return 0;
    }
    return 0;
}
