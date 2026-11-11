#include<bits/stdc++.h>
using namespace std;
long long a[200005];long long cnt=-1;long long b[200005];
long long id,h;int j=0;
int n,m;
int vis[200005];
bool cmp(int o,int p){
return o>p;
}
void dfs(int u){
if(u==m){
        cout<<h;
    if(h>=id){
        id=h;
        return;
    }
}
    else{
        for(int i=2;i<=n;i++){
            if(vis[i])continue;
            vis[i]=1;
            b[u]=h;
             h=h&a[i];
            dfs(u+1);
            vis[i]=0;
            h=b[u];
        }
    }
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>m>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
    cnt=max(cnt,a[i]);
    if(a[i]%2==0)j=1;
}
if(m==1)
{
 cout<<cnt;
 return 0;
}
if(m==n){
    long long ans=a[1];
    for(int i=2;i<=n;i++){
        ans=ans&a[i];
    }
    cout<<ans;
    return 0;
}
if(m==n-1){
    sort(a+1,a+1+n);
    long long k=a[2];
    for(int i=3;i<=n;i++){
        k=k&a[i];
    }
    cout<<k;
    return 0;
}
if(j==0){
        long long k=a[1];
    sort(a+1,a+n+1,cmp);
    for(int i=2;i<=m;i++){
        k=k&a[i];
    }
   cout<<k;
   return 0;
}
else{
      dfs(1);cout<<id;
    }
return 0;
}
