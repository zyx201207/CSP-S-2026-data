#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,m;
long long idx[305];
long long arr[305];
int way[305][305];
int sum;
void dfs(int l,int r,int x,int cnt){
    if(x==r&&cnt==way[l][r]){
        sum++;
    }else{
        for(int i=x+1;i<=r;i++){
            if(way[x][i]==1){
                dfs(l,r,i,cnt+1);
            }else{
                break;
            }
        }
    }
    return;
}
void solve( ){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",idx+i);
    }
    for(int i=1;i<=n;i++){
        arr[i]=idx[i]-idx[1];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            way[i][j]=INT_MAX;
            if(arr[j]-arr[i]<=m){
                way[i][j]=1;
            }else{
                for(int k=j-1;k>=i+1;k--){
                    if(arr[j]-arr[k]<=m){
                        way[i][j]=min(way[i][j],way[i][k]+1);
                    }else{
                        break;
                    }
                }                
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sum=0;
            dfs(i,j,i,0);
            if(sum==2){
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return;
}
int main( ){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    for(int i=1;i<=t;i++){
        solve( );
    }
    return 0;
}
//8