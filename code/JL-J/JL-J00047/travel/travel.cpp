#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string n1,n2,a1,a2;
    char z3,z6;
    cin>>n1>>a1>>z3>>n2>>a2>>z6;
    if(n1 == n2) cout<<1;
    else{
        cout<<0000;
        return 0;
    }
    if(a1 == a2){
        cout<<1;
        if((z3 == 'A'|| z3 == 'B' || z3 == 'C') && (z6 == 'A' || z6 == 'B' || z6 == 'C')) || ((z3 == 'D' || z3 == 'F') && (z6 == 'D' || z6 == 'F')) cout<<1;
        else{
            cout<<000;
            rturn 0;
        }
        if(z3 == 'A' && z6 == 'B') || (z3 == 'B' || z6 == 'A') || (z3 == 'B' || z6 == 'C') || (z3 == 'C' || z6 == 'B') || (z3 == 'D' || z6 == 'F') || (z3 == 'F' || z6 == 'D') cout<<1;
        else{
            cout<<00;
            return 0;
        }
    }
    else cout<<0;
    return 0;
}
