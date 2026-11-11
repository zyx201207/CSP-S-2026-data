#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using ui=unsigned int;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define fs first
#define sc second
#define pb push_back
#define lb(x) ((x)&(-(x)))
template<typename T>void chkmin(T& a,T b){
    if(a>b)a=b;
}
template<typename T>void chkmax(T& a,T b){
    if(a<b)a=b;
}
void fileIO(string s){
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
ll n,m;
ll a[500005];
int main(){
    fileIO("crystal");
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",a+i);
    sort(a+1,a+n+1);
    ll sum=0;
    int l=1,ans=0;
    for(int r=1;r<=n;r++){
        sum+=a[r];
        while(l<=r&&(a[r]*(r-l+1)-sum>m))sum-=a[l++];
        chkmax(ans,r-l+1);
    }
    printf("%lld",ans);
}
