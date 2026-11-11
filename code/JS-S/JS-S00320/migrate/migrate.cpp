#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
long long x[maxn];
long long c,t,n,d;
bool check1(){
    long long Delta=x[2]-x[1];
    for(long long i=2;i<=n;i++)
        if(Delta!=x[i]-x[i-1])
            return false;
    return true;
}
void solve1(){
    long long Delta=x[2]-x[1];
    if(Delta>d){cout<<0<<'\n';return;}
    long long Move=d/Delta,ans=0;
    for(long long i=1;i<=n;i++){
        if(i+Move>=n)continue;
        ans+=(n-i)-(n-i)/Move-Move+1;
    }
    cout<<ans<<'\n';
}
void solve(){
    cin>>n>>d;
    for(long long i=1;i<=n;i++){
        cin>>x[i];
    }
    if(check1())solve1();
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>c>>t;
    for(long long i=1;i<=t;i++){
        solve();
    }
    return 0;
}
