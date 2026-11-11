#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],mx;
void dfs(long long nw,long long k,long long ans){
    if(nw==n+1){
        mx=max(mx,ans);
        return;
    }
    if(k){
        dfs(nw+1,k-1,ans);
    }
    if(n-nw-k+1){
        dfs(nw+1,k,(ans&a[nw]));
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,n-m,1073741823);
    cout<<mx;
    return 0;
}
