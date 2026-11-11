#include<bits/stdc++.h>
#define pcr(i,a,b,c) for(int i=a;i<=b;i+=c)
#define rcp(i,a,b,c) for(int i=a;i>=b;i-=c)
#define pii pair<int,int>
#define pil pair<int,ll>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=5e5+3;
const int mod=998244353;
const ll inf=1e9;
int n,ans;
ll m,a[N],diff[N],pre[N];
void solve(){
    cin>>n>>m;
    pcr(i,1,n,1) cin>>a[i];
    sort(a+1,a+n+1);
    pcr(i,1,n-1,1){
        diff[i]=a[i+1]-a[i];
        pre[i]=pre[i-1]+diff[i];
    }
    ll num=0;
    int i=1,j=1;
    while(j<=n){
        int len=j-i+1;
        while(j<=n&&num+diff[j]*len<=m){
            num+=diff[j]*len;
            j++;
            len=j-i+1;
        }
        ans=max(ans,len);
        num-=(pre[j-1]-pre[i-1]);
        i++;
        if(diff[j]>m){
            while(j<=n&&diff[j]>m) j++;
            i=j;num=0;
        }
    }
    cout<<ans;
    return;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    T=1;
    while(T--) solve();
    return 0;
}
