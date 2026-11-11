#include<bits/stdc++.h>
using namespace std;
int a,b;
string sa,sb;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> a >> sa >> b >> sb;
    if(a != b){
        cout << "0000";
        return 0;
    }
    string na = sa,nb = sb;
    na.pop_back(),nb.pop_back();
    if(na != nb){
        cout << "1000";
        return 0;
    }
    char ca = sa[2],cb = sb[2];
    if(ca >= 'D' && ca <= 'F' && cb >= 'D' && cb <= 'F'){
        cout << "1111";
        return 0;
    }
    else if(ca >= 'A' && ca <= 'C' && cb >= 'A' && cb <= 'C'){
        if(ca > cb) swap(ca,cb);
        if(ca == 'A' && cb == 'C'){
            cout << "1110";
        } else {
            cout << "1111";
        }
    }
    else    cout << "1100";
    return 0;
}