#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 2E5+5;
int n, a[N];
char c[N];
pii findix(int x) {
    for(int i=1;i<=n;i++) {
        if(x>a[i]) x-=a[i];
        else return make_pair(i, x);
    }
    return make_pair(0, 0);
}
signed main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int sum=0;
    for(int i=1;i<=n;i++) {
        cin>>a[i]>>c[i];
        sum += a[i];
    }
    pii s=findix(sum/2), t=findix(sum%2==0?sum/2+1:sum/2+2);
    int ans = 0;
    while(s.first != 0 && t.first != n+1) {
        int sub1 = s.second, sub2=a[t.first]-t.second+1;
        if(sub1 < sub2) {
            if(c[s.first] != c[t.first]) ans += sub1;
            s.first --, s.second = a[s.first];
            t.second += sub1;
        } else if(sub1 > sub2) {
            if(c[s.first] != c[t.first]) ans += sub2;
            t.first ++, t.second = 1;
            s.second -= sub2;
        } else {
            if(c[s.first] != c[t.first]) ans += sub1;
            s.first --, s.second = a[s.first];
            t.first ++, t.second = 1;
        }
    }
    cout << ans << '\n';

    return 0;
}