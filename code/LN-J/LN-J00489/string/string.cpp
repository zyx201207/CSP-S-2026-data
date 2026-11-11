#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define db cerr<<"fff"<<'\n';
struct node{
    int a;
    char c;
};
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<node> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].a >> a[i].c;
    }
    for (int i = 1; i < a.size(); i++) {
        if (a[i].c == a[i-1].c) {
            a[i-1].a+=a[i].a;
            a.erase(a.begin()+i);
            i--;
        }
    }
    long long ans = 0;
    while(a.size()!= 1) {
        int fdsa = min(a[0].a,a.back().a);
        if (a[0].c != a.back().c) ans += fdsa;
        a[0].a -= fdsa;
        a.back().a -= fdsa;
        if (a[0].a == 0)a.erase(a.begin());
        if (a.back().a == 0)a.pop_back();
    }
    cout << ans;

    return 0;
}
