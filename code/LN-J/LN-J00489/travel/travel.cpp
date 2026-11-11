#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a1,a2,b1,b2;
    char a3,b3;
    string afdsa,bfdsa;
    cin >> a1 >> afdsa >> b1 >> bfdsa;
    a3=afdsa.back();afdsa.pop_back();
    b3=bfdsa.back();bfdsa.pop_back();
    a2=(int)(afdsa[0]-'0')*10+(int)(afdsa[1]-'0');
    b2=(int)(bfdsa[0]-'0')*10+(int)(bfdsa[1]-'0');
    if(a1==b1) {
        cout<<1;
        if(a2==b2) {
            cout<<1;
            if(!(a3<='C'&&b3<='C')||(a3>'C'&&b3>'C')) cout<<0<<0;
            else {
                cout<<1;
                if(abs(a3-b3) == 1) {
                    cout<<1;
                }else cout<<0;
            }
        }else cout<<0<<0<<0;
    } else cout<<0<<0<<0<<0;

    return 0;
}
