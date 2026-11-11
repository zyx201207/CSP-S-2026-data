#include<bits/stdc++.h>
#define rep(i,l,r) for(int qwp=(r),i=(l);i<=qwp;i++)
#define per(i,r,l) for(int qwp=(l),i=(r);i>=qwp;i--)
using namespace std;
typedef long long ll;
constexpr int N=5e5+5;
int n;ll m,a[N],s[N];
inline bool check(int l,int r){
    ll x=s[r]-s[l-1],y=a[r]*(r-l+1);
    return y-x<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;rep(i,1,n)cin>>a[i];
    sort(a+1,a+n+1);rep(i,1,n)s[i]=s[i-1]+a[i];
    int ans=0;for(int i=1,j=1;i<=n;i++){
        while(!check(j,i))j++;
        ans=max(ans,i-j+1);
    }
    cout<<ans<<'\n';
    return 0;
}
/*
ulimit -v 1048576;ulimit -s 1048576
g++ -O2 -std=c++14 -static crystal.cpp -o %;size %;time ./%
ulimit -s 1048576
g++ -O2 -std=c++14 -fsanitize=address,leak,undefined crystal.cpp -o %;size %;time ./%
*/