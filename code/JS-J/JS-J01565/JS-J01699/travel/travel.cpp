#include<iostream>
using namespace std;

bool check(string x , string y){
    if(x[2] == 'A' && y[2] == 'B') return true;
    if(x[2] == 'B' && y[2] == 'A') return true;
    if(x[2] == 'C' && y[2] == 'B') return true;
    if(x[2] == 'B' && y[2] == 'C') return true;
    if(x[2] == 'D' && y[2] == 'F') return true;
    if(x[2] == 'F' && y[2] == 'D') return true;
    return false;
}
int main(){
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a , b , c , d;
    cin >> a >> b >> c >> d;
    if(a != c){
        cout << "0000";
        return 0;
    }
    if(b[0] != d[0] || b[1] != d[1]){
        cout << "1000";
        return 0;
    }
    if(!((b[2] == 'A' || b[2] == 'B' || b[2] == 'C') && (d[2] == 'A' || d[2] == 'B' || d[2] == 'C') || (b[2] == 'F' || b[2] == 'D') && (d[2] == 'F' || d[2] == 'D'))){
        cout << "1100";
        return 0;
    }
    if(!(check(b , d))){
        cout << "1110";
    }else{
        cout << "1111";
    }
    return 0;
}
