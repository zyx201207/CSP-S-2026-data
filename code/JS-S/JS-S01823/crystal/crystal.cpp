#include <bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500005];
long long s[500005];

bool cmp(int x,int l) {
    //cout << a[x] * (x - l + 1) - (s[x] - s[l - 1]) << ' ';
    return a[x] * (x - l + 1) - (s[x] - s[l - 1]) <= m;
}

int main() {
    /*
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    */
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n);
    for(int i = 1;i <= n;i ++) {
        s[i] = s[i - 1] + a[i];
        //cout << s[i] << ' ' << a[i] << endl;
    }
    int res = 0;
    int l = 1;
    for(int i = 1;i <= n;i ++) {
        while(!cmp(i,l)) {
            //cout << l << ' ' << i << endl;
            l ++;
        }
        //cout << endl;
        res = max(res,i - l + 1);
    }
    cout << res;
    return 0;
}
