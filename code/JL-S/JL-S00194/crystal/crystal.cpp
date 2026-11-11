#include <bits/stdc++.h>
#define endl "\n"
#define con continue
#define ret return
#define pb push_back
#define claer clear
#define rp(i,a,b) for(int i=(a);i<=(b);i++)
#define pr(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
#define int long long
#define N 500005
void out(){
    cout<<endl;
}
template<class X,class ...Y>
void out(X x,Y...y){
    cout<<x;
    if(sizeof...(y)>0) cout<<" ";
    out(y...);
}
int a[N];
int sum[N];
void solve(){
    int n,m;
    cin>>n>>m;
    int len=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    rp(i,1,n){
        sum[i]=sum[i-1]+a[i];
    }
    int ans=1;
    for(int i=1;i<=n;i++){
        while(i+len-1<=n){
            int r=i+len-1;
            if(len*a[r]-(sum[r]-sum[i-1])<=m){
                len++;
            }
            else break;
        }
        len--;
        ans=max(len,ans);
    }
    out(ans);
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    solve();
}
