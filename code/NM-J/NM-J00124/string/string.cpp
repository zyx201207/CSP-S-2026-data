#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("string.in", "r", stdin);
    //freopen("string.out", "w", stdout);
    string a, e, f;
    int b;
    long long c, g;
    char d;
    cin >> b;
    g = 0;
    for(int i = 1; i <= b; i++){
        cin >> c >> d;
        e[i] = d;
        f[i] = c;
        for(int j = 1; j > c; j++){
            a[j] = d;
        }
    }
    for(int i = 2; i <= b; i++){
        if(e[i] != e[i-1]) g += f[i];
    }
    cout << g;
    return 0;
}

