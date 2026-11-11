#include<bits/stdc++.h>
using namespace std;
int c;
int n;
constexpr int N=5e2+5;
int k[N];
constexpr int K=5e5+5;
int a[N][K],t[N][K];
int m;
constexpr int M=5e5+5;
int w[M];
int q;
constexpr int Q=1e5+5;
int x[Q],y[Q];
int d;
int ans=0;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)
    {
        cin >> w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin >> a[i][j] >> t[i][j];
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin >> x[i] >> y[i];
        for(int j=x[i];j<=y[i];j++)
        {
            ans+=max({a[i][j],w[i],w[j]});
        }
        cout << ans << '\n';
    }
    return 0;
}
