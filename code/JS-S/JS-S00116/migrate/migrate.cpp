#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
constexpr int maxn=2e6+5;
ull n,d;
ll a[maxn];
bool ist[maxn];
int sm[maxn];
ll ans;
int c,T;
void slv(){
    cin>>n>>d;
    ans=0;
    for (int i=1;i<=n;i++) ist[i]=0,sm[i]=0;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=3;i<=n;i++){
        if (a[i]-a[i-2]<=d) ist[i-2]=1;
    }
    for (int i=1;i<=n;i++) sm[i]=sm[i-1]+ist[i];
    for (int L=2;L<=n;L++){
        for (int i=1;i+L<=n;i++){
            if (sm[i+L-2]-sm[i-1]==1) ans++;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while (T--){
        slv();
    }
    return 0;
}
//?
