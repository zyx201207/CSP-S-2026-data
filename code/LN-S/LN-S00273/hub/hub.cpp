#include<bits/stdc++.h>
using namespace std;
int c;
int t;
int n;
constexpr int N=1e6+5;
int u[N],v[N],w[N];
int k;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(w,N,sizeof(w));
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i=1;i<=n;i++)
        {
            cin >> u[i] >> v[i];
            w[abs(u[i]-v[i])]++;
        }
        sort(w+1,w+n+1);
        cout << w[1] << '\n';
        memset(w,N,sizeof(w));
    }
    return 0;
}
