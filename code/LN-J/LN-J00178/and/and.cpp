#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e5;
const int maxm=(1<<30);
ll n,m,ans=0;
int a[maxn];
void dfs(int x,int y,int z){
    if(y==m){
        ans=max(ans,1LL*z);
        return ;
    }
    if(x>=n) return ;
    if(y==0) dfs(x+1,y+1,a[x+1]);
    else dfs(x+1,y+1,(z&a[x+1]));
    dfs(x+1,y,z);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    dfs(1,0,0);
    dfs(1,1,a[1]);
    printf("%lld",ans);
    return 0;
}
