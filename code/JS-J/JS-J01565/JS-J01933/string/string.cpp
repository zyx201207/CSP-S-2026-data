#include <bits/stdc++.h>
using namespace std;
long long n, a, num = 0, g;
char c;
bool huiwen(string x){
    for (long long i = 0;i <= g / 2;i++){
        if (x[i] != x[g - i - 1]){
            return 0;
        }
    }
    return 1;
}
string s;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (long long i = 1;i <= n;i++){
        cin >> a;
        g += a;
        cin >> c;
        for (long long j = 1;j <= a;j++){
            s += c;
        }
    }
    if (huiwen(s)){
        cout << 0;
        return 0;
    }
    if (a >= 1000000000){
        cout << g / 2 * a;
    }
    else{
        long long l = 0;
        long long r = g - 1;
        while(l < r){
            if (s[l] != s[r]){
                num++;
            }
            l++;
            r--;
        }
        cout << num;
    }
    return 0;
}
