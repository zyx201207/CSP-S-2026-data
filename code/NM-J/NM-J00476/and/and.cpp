#include<bits/stdc++.h>
using namespace std;
int n,m,f[200005];
long long a[200009],re=0;
void dfs(int x,int i){
    f[i]=a[x];
    if(i==m){
        long long ans=f[1];
        for(int j=2;j<=m;j++){
            ans=ans&f[j];
        }
        re=max(re,ans);
        return;
    }
    for(int j=x+1;j<=n;j++){
        dfs(j,i+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    if(m==1){
        long long ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
        printf("%lld",ans);
        return 0;
    }
    //
    if(m==n){
        long long ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        printf("%lld",ans);
        return 0;
    }
    //
    if(m==2){
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        printf("%lld",ans);
        return 0;
    }
    //
    long long ans=0;
    for(int i=1;i<=n;i++){
        re=0;
        dfs(i,1);
        ans=max(ans,re);
    }
    printf("%lld",ans);
    return 0;
}
