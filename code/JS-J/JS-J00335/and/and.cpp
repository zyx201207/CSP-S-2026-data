#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,maxn=0;
ll a[200010];
void dfs(ll x,ll y,ll sum){
    if(y==0){
        maxn=max(maxn,sum);
        return ;
    }
    sum=sum&a[x];
    for(ll i=x+1;i<=n+1;i++){
        dfs(i,y-1,sum);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=n-m;i++){
        dfs(i,m,a[i]);
    }
    cout<<maxn<<endl;
    return 0;
}
