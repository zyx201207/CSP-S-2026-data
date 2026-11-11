#include<bits/stdc++.h>
using namespace std;
#define int long long

string a,b,c,d;

bool check(string a,string b){
    char n = a[2],m = b[2];
    if((n == 'A' && (m == 'B' || m == 'C')) || (n == 'B' && (m == 'A' || m == 'C')) || (n == 'C' && (m == 'A' || m == 'B')) || (n == 'D' && m == 'E') || (n == 'E' && m == 'D')){
        return true;
    }
    return false;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> b >> c >> d;
    if(a == c){
        cout << 1;
    }else{
        cout << "0000";
        return 0;
    }
    string t1 = b.substr(0,2);
    string t2 = d.substr(0,2);
    if(t1 == t2){
        cout << 1;
    }else{
        cout << 0;
    }
    if(t1 == t2 && check(b,d)){
        cout << 1;
    }else{
        cout << 0;
    }
    if(t1 == t2){
        if((b[2] == 'A' && d[2] == 'B') || (b[2] == 'B' && (d[2] == 'A' || d[2] == 'C')) || (b[2] == 'C' && d[2] == 'B') || (b[2] == 'D' && d[2] == 'E') || (b[2] == 'E' && d[2] == 'D')){
            cout << 1;
        }else{
            cout << 0;
        }
    }else{
        cout << 0;
    }

    return 0;
}
