#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,a3,a4;cin >> a1 >> a2 >> a3 >> a4;
    if (a1 == a3) cout << '1';
    else{
        cout << "0000";
        return 0;
    }
    if (a2[0] == a4[0] && a2[1] == a4[1]) cout << '1';
    else{
        cout << "000";
        return 0;
    }
    if ((a2[2] > 'C' && a4[2] > 'C') || (a2[2] <= 'C' && a4[2] <= 'C')) cout << '1';
    else{
        cout << "00";
        return 0;
    }
    if (abs((a2[2]-'0') - (a4[2]-'0')) == 1) cout << '1';
    else cout << '0';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
