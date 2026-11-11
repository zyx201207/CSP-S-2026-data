#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans=INT_MIN,a[N],v[N];
void dfs(int cur,int h){
    if(h==m){
        ans=max(cur,ans);
        return;
    }
    for(int i=1;i<=n;i++){
        if(v[i]==0){
            v[i]=1;
            if(h==0) dfs(a[i],h+1);
            else dfs(cur&a[i],h+1);
            v[i]=0;
        }
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}
