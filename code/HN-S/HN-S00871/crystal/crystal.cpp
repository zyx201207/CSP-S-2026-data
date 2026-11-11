#include<bits/extc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;

int n;
ll m;
ll a[N];

ll s[N];

void Solve(){
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
    int l=1,r=l,res=0;
    for(;r<=n;++r){
        for(;l<=r&&a[r]*(r-l+1)-(s[r]-s[l-1])>m;++l);
        res=max(res,r-l+1);
    }
    cout<<res<<"\n";
}

int main(){
    auto ___=freopen("crystal.in","r",stdin);
    auto _=freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];

    Solve();
    
    return 0;
}
