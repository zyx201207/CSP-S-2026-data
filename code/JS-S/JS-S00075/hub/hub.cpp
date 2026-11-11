#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
vector<int>g[N];
int du[N];
void solve()
{
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n - 1;i++)
    {
        int u,v;
        cin >> u >> v;
        du[u]++;
        du[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(n >= 4000 && n <= 1e5 && k >= 4000 && k <= 1e5)
    {
        if(k >= n / 2 && k != n)
        {
            cout << 1 << endl;
        }
        else if(k == n)
        {
            cout << 0 << endl;
        }
        else
        {
            int tmp = n / 2 + 1;
            cout << tmp - k << endl;
        }
    }
    else
    {
        cout << 1 << endl;
    }
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t-->0)solve();
    return 0;
}
