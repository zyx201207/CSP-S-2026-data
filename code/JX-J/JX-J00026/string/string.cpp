#include<bits/stdc++.h>
using namespace std;

struct unstr{
    int c;
    string d;
}a[200005];

int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt = 0;
    string t;
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> a[i].c >> a[i].d;
        for(int j = 0;j < a[i].c;j++) {
            t += a[i].d;
        }
    }
    int z = t.length();
    for(int i = 0;i < z / 2;i++) {
        if(t[i] != t[z - i - 1]) {
            cnt += 1;
        }
    }
    cout << cnt << endl;
    return 0;
}
