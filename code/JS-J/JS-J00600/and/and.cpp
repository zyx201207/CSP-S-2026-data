#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[200005],sum=-1,maxn=-1;
void dfs(int idx,int cnt,int ans){
    if(idx>n){
        if(cnt==m)maxn=max(maxn,ans);
        return;
    }
    if(cnt>m)return;
    if(ans<maxn)return;
    if(ans==-1)dfs(idx+1,cnt+1,a[idx]);
    else dfs(idx+1,cnt+1,ans&a[idx]);
    dfs(idx+1,cnt,ans);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        if(sum==-1)sum=a[i];
        else sum&=a[i];
    }
    if(m==1){
        cout<<maxn<<endl;
    }else if(m==n){
        cout<<sum<<endl;
    }else if(m==2){
        maxn=-1;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn<<endl;
    }else{
        maxn=-1;
        dfs(1,0,-1);
        cout<<maxn<<endl;
    }
    return 0;
}
