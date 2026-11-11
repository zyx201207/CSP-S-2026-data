#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,maxn,a[200001];
bool vis[200001],flag=1;
void dfs(long long cnt,long long num,long long andnum){
    if (num==m){
        if (andnum>ans){
            ans=andnum;
        }
        return;
    }
    if (n-cnt<m-num-1)
        return;
    for (int i=cnt;i<=n;i++){
        if (vis[i]==0){
            vis[i]=1;
            if (num==0){
                dfs(cnt+1,num+1,a[i]);
            }
            else
                dfs(cnt+1,num+1,andnum&a[i]);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    dfs(1,0,0);
    printf("%lld",ans);
}
