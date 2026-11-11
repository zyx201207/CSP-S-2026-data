#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll num[200005];
ll maxn=-1;
ll box[200005],vis[200005];
void dfs(ll x){
    if(x==m+1){
        ll temp=box[1];
        for(int i=1;i<=m;i++){
            temp&=box[i];
        }
        maxn=max(maxn,temp);
        return ;
    }
    for(ll i=1;i<=n;i++){
        if(vis[i]==0){
            box[x]=num[i];
            vis[i]=1;
            dfs(x+1);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    ll maxnn=-1;
    for(ll i=1;i<=n;i++){
        cin>>num[i];
        maxnn=max(maxnn,num[i]);
    }
    if(m==1){
        cout<<maxnn;
        return 0;
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j)maxn=max(num[i]&num[j],maxn);
            }
        }
        cout<<maxn;
        return 0;
    }else{
        dfs(1);
        cout<<maxn;
    }
    return 0;
}
