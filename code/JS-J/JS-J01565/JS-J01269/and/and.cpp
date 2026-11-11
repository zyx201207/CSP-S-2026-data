#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m,ans=0;
void dfs(int dep,int x,int sum){
    if(dep==m){
        ans=max(ans,sum);
    }
    else{
        if(n-x+1>m-dep){
            dfs(dep,x+1,sum);
        }
        if(dep==0){
            dfs(dep+1,x+1,a[x]);
        }
        else{
            dfs(dep+1,x+1,sum&a[x]);
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    if(m==1){
        ans=a[n];
    }
    else if(m==n){
        ans=a[n];
        for(int i=n-1;i>=1;i--){
            ans=ans&a[i];
        }
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
    }
    else if(m==n-1){
        for(int i=1;i<=n;i++){
            int sum=-1;
            for(int j=1;j<=n;j++){
                if(i!=j){
                    if(sum==-1){
                        sum=a[j];
                    }
                    else{
                        sum=sum&a[j];
                    }
                }
            }
            ans=max(ans,sum);
        }
    }
    else if(n<=20){
        dfs(0,1,0);
    }
    else{
        ans=a[n];
        for(int i=n-1;i>=n-m+1;i--){
            ans=ans&a[i];
        }
    }
    
    printf("%d",ans);
    return 0;
}