#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>mp;
int a[200005],ans;
int n,m;
void dfs(int d,int sum){
    if(d==m){
        ans=max(ans,sum);
        return;
    }
    for(int i=1;i<=n;i++){
        if(mp[i]==1){
            continue;
        }
        mp[i]=1;
        dfs(d+1,(sum&a[i]));
        mp[i]=0;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        mp[i]=1;
        dfs(1,a[i]);
        mp[i]=0;
    }
    printf("%d",ans);
    return 0;
}
