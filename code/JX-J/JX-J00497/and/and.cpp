#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m,maxa=0,a;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> a;
        if (a>maxa) maxa = a;
    }
    if (m==1) cout << maxa;
    return 0;
}
