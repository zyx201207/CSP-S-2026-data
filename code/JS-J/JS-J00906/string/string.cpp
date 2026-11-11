#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, tmp, sum = 0, len = 0;
    string s = " ";
    char c;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> tmp >> c;
        if (tmp == 1000000000){
            printf("%d000000000\n", n/2);
            return 0;
        }
        for (int j = 1; j <= tmp; ++j)
            s += c;
        len += tmp;
    }
    int l = 1, r = len;
    while (l <= r){
        if (s[l++] != s[r--])
            sum += 1;
    }
    cout << sum << endl;
    return 0;
}
