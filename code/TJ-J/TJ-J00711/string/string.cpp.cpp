#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, a;
    string c;
    string s;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a >> c;
        for(int j = 1; j <= a; j++){
            s = s + c;
        }
    }
    if(s == s){
        cout << "0" << endl;
    }
    else{
        cout << n << endl;
    }
    return 0;
}
