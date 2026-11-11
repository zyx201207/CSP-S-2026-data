#include <bits/stdc++.h>
using namespace std;
int main (){
    freopen ("travel.in","r",stdin);
    freopen ("travel.out","w",stdout);
    string n,m,n1,m1;
    cin>>n>>n1>>m>>m1;
    if (n == m) {
        cout<<1;
        char a,b,c,d;
        a=n1[1];
        b=m1[1];
        c=n1[0];
        d=n1[0];
        if (a==b and c==d){
            cout<<1;
            a=n1[2];
            b=m1[2];
            if (int(a-64)+int(b-64) <= 5 or int(a-64)+int(b-64) == 10) {
                cout<<1;
                if (int(a-64) - int(b-64) == 1 || int(b-64) - int(a-64) == 1 || a == 'D'  and b=='F' || a=='F' and b=='D' )cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
