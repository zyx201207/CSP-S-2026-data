#include <bits/stdc++.h>
using namespace std;
int a,b,a2,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a;
    string a1,b1;
    cin >> a1 >> b >> b1;
    a2=(a1[0]-'0')*10+a1[1]-'0';
    b2=(b1[0]-'0')*10+b1[1]-'0';
    if(a==b){
        cout<<'1';
        if(a2==b2){
            cout << 1;
            if(a1[2]<'D' && b1[2]<'D'){
                cout << 1;
                if(a1[2]-b1[2]==1 || b1[2]-a1[2]==1){
                    cout << 1;
                }else cout<<0;
            }else if(a1[2]>='D' && b1[2]>='D'){
                cout << 1;
                cout << 1;
            }else {
                cout << 0 << 0;
            }
        }
        else cout <<0 << 0 <<0;
    }
    else cout << "0000";
    return 0;
}
