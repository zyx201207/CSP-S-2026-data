#include <bits/stdc++.h>
using namespace std;
int n,m,a[2000001];
int ans=0;
int dfs(int i,int x,int l ){
    if(l==m+1){
        return x;
    }
    for(int j=i;j<=n;j++)
        x&=a[j],dfs(i,x,l+1);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n-m;i++){
        int x=a[i],l=1;
        ans=max(ans,dfs(i,x,l));
    }
    printf("%d",ans);
    return 0;
}
