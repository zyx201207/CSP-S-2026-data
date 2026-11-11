#include<bits/stdc++.h>
using namespace std;typedef long long ll;
ll n,m,a[2000005],sum=-1;
void dfs(ll now,ll mx,ll stp){
    if(stp>m){
        sum=max(sum,mx);return;
    }for(ll i=now+1;i<=n;i++){
        if(stp+(n-i+1)>=m){dfs(i,(mx&a[i]),stp+1);}
    }
}
int main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];}
    for(int i=1;i<=n;i++){
        dfs(i,a[i],2);
    }cout<<sum;
    return 0;
}
