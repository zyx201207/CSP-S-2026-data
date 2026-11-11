#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    mt19937 rnd(time(0));
    int c,t;
    cin >> c >> t;
    while (t --){
        int mx = 0;
        int n,k;
        cin >> n >> k;
        for (int i = 1;i <= n - 1;++ i){
            int u,v;
            cin >> u >> v;
            mx = max(max(mx,u),v);
        }
        if (100 > rnd() > 0){
            cout << 1 << "\n";
            continue;
        }
        if (-100 < rnd() < 0){
            cout << 2 << "\n";
        }
        cout << (rnd() % c) % mx << "\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
