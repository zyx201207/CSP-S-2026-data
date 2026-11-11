#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    string s = "",s2="";
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        char c;
        cin >> a >> c;
        while (a--) s+=c,s2=c+s2;
    }
    long long cnt=0;
    for (long long i = 0; i < s.size() / 2; i++) {
        cnt+=(s[i] != s2[i]);
    }
    cout << cnt;
    return 0;
}
