#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const ll INF = 0x3f;
#define endl '\n'
const int N = 1e5+5;
signed main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string s1, s2;
    int c1, c2;
    cin >> c1 >> s1 >> c2 >> s2;
    int x1, x2, m1, m2;
    x1 = (s1[0]-'0')*10+s1[1]-'0';
    x2 = (s2[0]-'0')*10+s2[1]-'0';
    m1 = s1[2]-'A'+1, m2 = s2[2]-'A'+1;
    if(m1 == 6) m1 = 5;
    if(m2 == 6) m2 = 5;
    if(c1 == c2){
        cout << 1;
        if(x1 == x2){
            cout << 1;
            if((m1 <= 3 && m2 <= 3) || (m1 >= 4 && m2 >= 4)){
                cout << 1;
                if(m1-m2 == 1 || m1-m2 == -1){
                    cout << 1;
                }else{
                    cout << 0;
                }
            }else{
                cout << "00";
            }
        }else{
            cout << "000";
        }
        
    }else{
        cout << "0000";
    }
    cout << endl;
    return 0;
}