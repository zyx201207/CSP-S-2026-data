#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string n1,m1,n2,m2;
    cin >> n1 >> m1 >> n2 >> m2;
    if(n1 == n2){
        cout << "1";
    }
    else{
        cout << "0000";
        return 0;
    }
    if(m1[0] == m2[0] && m1[1] == m2[1]){
        cout << "1";
    }
    else{
        cout << "000";
        return 0;
    }
    if((m1[2] <= 'C' && m2[2] <= 'C') || (m1[2] >= 'D' && m2[2] >= 'D')){
        cout << "1";
    }
    else{
        cout << "00";
        return 0;
    }
    if(m1[2] >= 'D' && m2[2] >= 'D'){
        cout << "1";
    }
    else if(m1[2] == 'B' || m2[2] == 'B'){
        cout << "1";
    }
    else{
        cout << "0";
    }
    return 0;
}
