#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005];
void dfs(int ids,int sum,int num){
    if(sum>m){
        ans=max(ans,num);
        return;
    }
    if(ids>n){
        return;
    }
    dfs(ids+1,sum,num);
    if(num==0){
        dfs(ids+1,sum+1,a[ids]);
    }else{
        dfs(ids+1,sum+1,num&a[ids]);
    }

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,0,0);
    cout<<ans;
    return 0;
}
