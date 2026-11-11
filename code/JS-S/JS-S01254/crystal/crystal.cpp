#include<bits/stdc++.h>
#define long long int
using namespace std;
const int maxn=5e5+5;
int n,m,a[maxn],ans;
bool vis[maxn];
bool f=true,f2=true;
/*
void dfs(int step,int gt,int ml,int lst){
    if(step>=n-gt+1&&ml<=m){
        ans=n-gt+1;
        return;
    }
    if(ml>=m){
        if(ml==m)ans=max(step,ans);
        else ans=max(step-1,ans);
        return;
    }
    for(int i=gt+1;i<=n;i++){
        if(!vis[i]){
            vis[i]=true;
            dfs(step+1,gt,ml+(lst-a[i])*step,a[i]);
            vis[i]=false;
        }
    }
}
*/
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(a[i]!=i)f=false;
        if(i>=3)if(a[i]-a[i-1]!=a[i-1]-a[i-2])f2=false;
    }
    if(f){
        int heart=0;
        for(int i=1;i<=n&&heart<=m;i++){
            ans++;
            heart=i*(i+1)/2;
        }
        cout<<ans;
        return 0;
    }
    if(f2){
        int d=a[2]-a[1],heart=0;
        for(int i=1;i<=n&&heart<=m;i++){
            ans++;
            heart=i*(i+1)/2*d;
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        int cry=m,cnt=1,idx=i+1;
        while(cry>=0&&idx<=n){
            for(int j=i;j<idx;j++){
                cry-=(j-i+1)*(a[j+1]-a[j]);
            }
            cnt++,idx++;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
