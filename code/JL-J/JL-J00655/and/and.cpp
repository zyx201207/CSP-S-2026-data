#include<bits/stdc++.h>
#define maxn 200010
using namespace std;
int n,m,ans;
int a[maxn],memo[2010][2010];
inline int dfs(int root,int cnt,int chance){
    if(memo[root][chance]){
        return memo[cnt][chance];
    }
    if(root>n){
        return cnt;
    }
    if(chance==n-root+1){
        for(int i=root;i<=n;i++){
            cnt&=a[i];
        }
        return cnt;
    }
    if(cnt&a[root]==cnt){
        if(root<=2000&&chance<=2000){
            memo[root][chance]=dfs(root+1,cnt,chance-1);
            return memo[root][chance];
        }else{
            return dfs(root+1,cnt,chance-1);
        }
    }
    if(root<=2000&&chance<=2000){
        memo[root][chance]=max(dfs(root+1,cnt,chance),dfs(root+1,cnt&a[root],chance-1));
        return memo[root][chance];
    }else{
        return max(dfs(root+1,cnt,chance),dfs(root+1,cnt&a[root],chance-1));
    }
    
}
int main(){
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ans=dfs(0,-1,m);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}