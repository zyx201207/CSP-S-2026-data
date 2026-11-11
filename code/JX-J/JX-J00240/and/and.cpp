#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e9;
int n, m, a[200005];
ll ans, num=2, cnt, ans2, cnt2;
bool check[N+5];
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin>>n>>m;
    for (int i=1; i<=n; i++) cin>>a[i];
    check[2]=1;
    for (int i=2; i<30; i++) {
        num*=2;
        check[num]=1;
    }
    sort(a+1, a+1+n);
    for (int i=n; i>=1; i--) {
        if (check[a[i]]==0) {
            if (ans==0) ans=a[i];
            else ans=ans&a[i];
            cnt++;
        }
        if (cnt==m) break;
    }
    for (int i=n; i>=1; i--) {
        if (check[a[i]]) {
            if (a[i]!=a[i+1] && i!=n) {
                ans2=0;
                break;
            }
            if (ans2==0) ans2=a[i];
            cnt2++;
        }
        if (cnt2==m) break;
    }
    cout<<max(ans, ans2);
    return 0;
}
