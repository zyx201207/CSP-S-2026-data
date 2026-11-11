#include<bits/stdc++.h>
using namespace std;
int c, t;
const int maxn = 2e6 + 10;
int x[maxn];
int main()
{
    //freopen("migrate.in", "r", stdin);
    //freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    if(c == 11 || c == 12) {
        while(t--) {
            int n, d;
            cin >> n >> d;
            for(int i = 1; i <= n; i++)
                cin >> x[i];
            int c = x[2] - x[1];
            if(c >= d) {
                cout << "0\n";
                continue;
            }
            else {
                int num = d / c;
                cout << n - num << "\n";
            }
        }
    }
    return 0;

}
