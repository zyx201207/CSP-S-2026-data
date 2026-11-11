#include<bits/stdc++.h>
using namespace std;
int n,m,a[200020],dp[2020][2020],mx,ans,pos;
void dfs(int p,int k,int s){
    if(p>n){
        if(k==m) ans=max(ans,s);
        return;
    }
    if(k>m) return;
    if(p!=pos) dfs(p+1,k,s);
    dfs(p+1,k+1,s&a[p]);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        mx=max(mx,a[i]);
    }
    if(m==1) printf("%d",mx);
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++) ans=max(ans,a[i]&a[j]);
        }
        printf("%d",ans);
    }
    else if(m==n){
        for(int i=2;i<=n;i++) a[1]&=a[i];
        printf("%d",a[1]);
    }
    else{
        for(int i=1;i<=n-m+1;i++){
            pos=i;
            dfs(i,0,a[i]);
        }
        printf("%d",ans);
    }
}
