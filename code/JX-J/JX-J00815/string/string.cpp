#include <bits/stdc++.h>
using namespace std;
long long n;
string str;
long long len = 0;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (long long i=1; i<=n; i++){
        long long x; char c;
        cin >> x >> c;
        for (long long j=1; j<=x; j++) str += c;
        len += x;
    }
    long long tj=0;
    n = len;
    if (len % 2 == 0) len /= 2, len--;
    else len /= 2;
    for (long long i=0; i<len; i++){
        if (str[i] != str[n-i-1]){
            tj++;
        }
    }
    cout << tj;
    return 0;
}
//80 pts
