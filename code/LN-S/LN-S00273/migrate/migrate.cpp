#include<bits/stdc++.h>
#define int long long
using namespace std;
int c;
int t;
int n;
constexpr int N=2e6+5;
int x[N];
int d;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        for(int i=1;i<=n;i++)
        {
            cin >> x[i];
        }
        if((n-d)%d==0)
        {
            cout << (n-d)/d << '\n';
        }
        else
        {
            cout << (n-d+1)/d <<'\n';
        }
    }
    return 0;
}
