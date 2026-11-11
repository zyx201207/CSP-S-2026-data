#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
constexpr int maxn=2e6+10;
int a[maxn];
vector<int>gra[maxn];
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1,u,v;i<n;++i)
        {
            cin>>u>>v;
            gra[u].emplace_back(v);
            gra[v].emplace_back(u);
        }
        cout<<n/k-1<<endl;
    }
    return 0;
}