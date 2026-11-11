#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin >> n;
    string a = "",b = "";

    for (int i= 1;i <= n;i++) {
        int x;
        char c;
        cin >> x >> c;
        for (int i = 1;i <= x;i++) {
            a = a+c;
            b = c+b;
        }
    }

    int cnt = 0;
    for (int i = 0;i < a.size()/2;i++) {
        if (a[i] != b[i]) {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
