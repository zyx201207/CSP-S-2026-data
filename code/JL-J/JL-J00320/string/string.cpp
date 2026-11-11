#include <bits/stdc++.h>
using namespace std;
int n;
int a[200010];
char c[200010];
bool b = 0;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i] >> c[i];
    }
    for (int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            if (c[i] == c[j]) b = 1;
            else b = 0;
        }
    }
    if (b == 1) cout << "0";
    return 0;
}
