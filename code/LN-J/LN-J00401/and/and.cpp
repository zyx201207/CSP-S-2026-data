#include <bits/stdc++.h>
using namespace std;
int n,m,a[200000];
int dfs(int s,int m,int x){
    int ans=0;
    if(m==0)return x;
    if(s>n)return 0;
    for(int i=s;i<n-m+1;i++){
        ans=max(ans,dfs(i+1,m-1,x&a[i]));
    }
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d",dfs(0,m,(1<<30)-1));
    return 0;
}
