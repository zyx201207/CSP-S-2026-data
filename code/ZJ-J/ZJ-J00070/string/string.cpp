#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int a[N], n;
char ch[N];
long long ans;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    
    // freopen("string6.in", "r", stdin);
    // freopen("string6.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> ch[i];
    }
    int i = 1, j = n;
    int x = a[i], y = a[j];
    while(i < j) {
        if(ch[i] == ch[j]) {
            if(x > y) {
                j--;
                x -= y;
                y = a[j];
            } else if(x < y) {
                y -= x;
                i++;
                x = a[i];
            } else {
                i++, j--;
                x = a[i], y = a[j];
            }
        } else {
            if(x > y) {
                j--;
                x -= y;
                ans += y;
                y = a[j];
            } else if(x < y) {
                i++;
                y -= x;
                ans += x;
                x = a[i];
            } else {
                i++, j--;
                ans += x;
                x = a[i], y = a[j];
            }
        } 
    }
    cout << ans << endl;
    return 0;
}