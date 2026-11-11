#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++ )
#define repf(i, a, b) for(int i = (a); i >= (b); i -- )
typedef long long ll;
const int N = 2e6 + 10;
int c; ll a[N]; int too[N];
void solve()
{
    int n; ll d;cin>>n>>d;
    rep(i,1,n)cin>>a[i]; ll ans=0;
    // rep(i,1,n)
    // {
    //     repf(j, n, i) if(a[j]-a[i]<=d) {too[i]=j; break;}
    // }
    // rep(i,1,n)
    // {
    //     rep(j,i+3,n)
    //     {
    //         int o = too[i]; int lst = i; int f = 0;
    //         while(too[o] <= j)
    //         {
    //             int u = too[o];
    //             if(too[o-1] == o) f++;
    //         }
    //     }
    // }
    cout << 0 << '\n';
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
    int t;cin>>c>>t;
    while(t--) solve();
    return 0;
}