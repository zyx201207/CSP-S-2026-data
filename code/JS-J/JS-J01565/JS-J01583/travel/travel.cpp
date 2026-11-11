#include<bits/stdc++.h>
#define endl '\n'
#define pii pair<int,int>
using ll = long long;
using namespace std;
//constexpr int N = 1e6+1001;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    string ca_1,ca_2;
    string se_1,se_2;
    cin >> ca_1 >> se_1 >> ca_2 >> se_2;
    if(ca_1 == ca_2){
        if(se_1[0] == se_2[0] && se_1[1] == se_2[1]){
            char o = se_1[2],p = se_2[2];
            if(((o == 'A' || o == 'B' || o =='C')&&(p == 'A' || p == 'B' || p =='C'))||((o == 'D' || o == 'F')&&(p == 'D' || p == 'F'))){
                if((o == 'D' || o == 'F')||(o == 'B')||(p == 'B')){
                    cout << "1111\n";
               }
               else{
                    cout << "1110\n";
               }
            }
            else{
                cout << "1100\n";
            }
        }
        else{
            cout << "1000\n";
        }
    }
    else{
        cout << "0000\n";
    }
    return 0;
}

