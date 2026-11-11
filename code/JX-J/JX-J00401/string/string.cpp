#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in", "w", stdin);
    freopen("string.out", "r", stdout);
    long long n, a, cnt, slen;
    string s;
    char c;
    cin >> n;
    for (long long i = 1; i <= n; i++){
        cin >> a >> c;
        slen += a;
        for (long long j = 1; j <= a; j++){
            s[j] = c;
        }
    }
    for (long long i = 1; i < slen; i++){
        long long j = slen-1;
        if (i != j){
            cnt++;
        }
        j--;
    }
    return 0;
}
