#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    int cmp = 0;
    for(int i = 1; i <= n; i++){
        int x;
        string y;
        cin >> x >> y;
        for(int j = 1; j <= x; j++){
            s += y;
        }
        cmp += x;
    }
    string z;
    for(int i = 1; i <= cmp; i++){
        z[i] = s[cmp - i + 1];
    }
    int sum = 0;
    for(int i = 1; i <= cmp; i++){
        if(z[i] != s[i]){
            sum++;
        }
    }
    cout << sum / 2;
    return 0;
}
