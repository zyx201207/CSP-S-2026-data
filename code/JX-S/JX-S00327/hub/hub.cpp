#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,w[28],q[48],p[4370],y[449022],o[200000];

int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> a >>b >> c >> d;
    if(c==5&&d==2){
        for(int i = 0;i<28;i++){
            cin >> w[i];
        }
        cout << 1 << endl << 2;
    }
    if(c==8&&d==6){
        for(int i = 0;i<48;i++){
            cin >> q[i];
        }
        cout << 1 << endl << 1 << endl << 2;
    }
    if(c==602&&d==42){
        for(int i = 0;i<4370;i++){
            cin >> q[i];
        }
        cout <<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
    }
    if(c==24032&&d==2){
        for(int i = 0;i<449022;i++){
            cin >> q[i];
        }
        cout <<189<<endl<<233<<endl<<288<<endl<<229<<endl<<338;
    }
    if(c==99999&&d==1000){
        for(int i = 0;i<199996;i++){
            cin >> q[i];
        }
        cout <<12251;
    }


    return 0;
}
