#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 10,INF = 0x3f3f3f3f;
string s1,s2,c1,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2){
        cout << "0000";
        return 0;
    }
    cout << 1;
    char num1 = (s1[0] + s1[1]),num2 = (s2[0] + s2[1]),t1 = (s1[2]),t2 = (s2[2]);
    if(num1 != num2){
        cout << "000";
        return 0;
    }
    cout << 1;
    if((t1 >= 'A' && t1 <= 'C' && t2 >= 'D' && t2 <= 'F') || (t2 >= 'A' && t2 <= 'C' && t1 >= 'D' && t1 <= 'F')){
        cout << "00";
        return 0;
    }
    cout << 1;
    if(t1 == 'D' && t2 == 'F' || (t1 == 'F' && t2 == 'D')){
        cout << 1;
        return 0;
    }
    if(abs((int)t1 - (int)t2) != 1){
        cout << 0;
        return 0;
    }
    cout << 1;
    return 0;
}
