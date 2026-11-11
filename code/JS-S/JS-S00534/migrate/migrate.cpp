#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[200050];
void solve(){
    int n;
    ll d;
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    ll dis=x[2]-x[1];
    if(dis<=d)cout<<n-3<<"\n";
    else cout<<0;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)solve();
    return 0;
}
