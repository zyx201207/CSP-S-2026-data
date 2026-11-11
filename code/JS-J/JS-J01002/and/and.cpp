#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN=2e5+5;ll n,m;
ll a[MAXN];
bool vis[MAXN];
ll ee[MAXN];
ll ans;
ll maxx=-1;
void dfs(ll x,ll dep){
    ee[dep]=x;
    if(dep==m){
        ans=a[ee[1]];
        for(ll i=2;i<=m;i++){
            //cout<<ee[i]<<" ";
            ans=(a[ee[i]]&ans);
        }
        //cout<<"\n";
        if(ans>=maxx){
            maxx=ans;
        }
        return ;
    }
    for(ll i=1;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=1;

        dfs(i,dep+1);
        vis[i]=0;
    }

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
   cin>>n>>m;
   int maxxx=-1;
   for(ll i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]>maxxx) maxxx=a[i];
   }
   int ans=1;
    if(m==1) {cout<<maxxx;return 0;}
    if(m==n){
        for(int i=1;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    if(n<=2000){
        dfs(0,0);
        cout<<maxx;
        return 0;
    }else {
        sort(a+1,a+1+n,greater<int>());
        ans=a[1];
        for(int i=1;i<=m;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }



}
