#include <bits/stdc++.h>
using namespace std;
string s;
long long n, len, x;
void jia(int a, char t){
    for(int i = 1; i <= a; i++){
        s += t;
        len++;
    }
    return;
}
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(long long i = 1; i <= n; i++){
        int a;
        char t;
        cin >> a >>t;
        jia(a, t);
    }
    bool flag = true;
    for(long long i = 1; i <= len / 2; i++){
        if(s[i] != s[len - i]){
            flag = false;
            x++;
        }
    }
    if(flag){
        cout << x;
    }
    else{
        cout << x + 1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
