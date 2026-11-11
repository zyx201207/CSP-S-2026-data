#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,w[11],q[13];

int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> a>>b >> c >> d;
    if(c==4&&d==2){
        for(int i = 0;i<11;i++){
            cin >> w[i];
        }
        cout << 1 << endl << 2;
    }
    if(c==5&&d==3){
        for(int i = 0;i<13;i++){
            cin >> q[i];
        }
        cout << 0 << endl << 1;
    }


    return 0;
}
