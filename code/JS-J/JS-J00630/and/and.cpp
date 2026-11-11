#include<bits/stdc++.h>
#define ll long long

using namespace std;
ll a[200010];
ll ans=0;
int n,m;
void dfs(int pos,int dep,ll res){
    if(n-pos+1<m-dep)return ;
    if(dep==m){
        ans=max(ans,res);
        return ;
    }
    for(int i=pos;i<=n;i++){
        dfs(i+1,dep+1,res&a[i]);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);freopen("and.out","w",stdout);//read,write
    //don`t forget!!!!
    
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        dfs(i+1,1,a[i]);
    }
    cout<<ans;
    return 0;
}