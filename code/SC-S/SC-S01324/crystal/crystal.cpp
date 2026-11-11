#include<bits/stdc++.h>
#define rep(i,a,b) for(auto i=a;i<b;++i)
using namespace std;
ifstream inf("crystal.in");
ofstream ouf("crystal.out");
using lint=long long;
int main(){
    ios::sync_with_stdio(false),inf.tie(nullptr);
    int n;lint m;inf>>n>>m;
    vector<lint> a(n);
    for(auto&x:a) inf>>x;
    sort(a.begin(),a.end());
    auto l=0,ans=0;
    auto sum=0ll;
    rep(i,0,n){
        sum+=a[i];
        while(a[i]*(i-l+1)-sum>m) sum-=a[l],++l;
        ans=max(ans,i-l+1);
    }
    ouf<<ans<<'\n';
    return 0;
}