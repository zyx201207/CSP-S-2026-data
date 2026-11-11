#include<bits/stdc++.h>
using namespace std;
constexpr int maxn=5e5+10;
long long w[maxn],k[maxn],t[maxn][maxn],a[maxn][maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","W",stdout);

    int c,n,m,d,q;
    int mn=INT_MAX;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;++i)
    {
        cin>>w[i];
        mn=min(mn,w[i]);
    }
    cout<<mn;
    return 0; 
    for(int i=1;i<=n;++i)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];++j)
        {
            cin>>a[i][j]>>t[i][j]; 
        }
    }
    return 0;
}
}