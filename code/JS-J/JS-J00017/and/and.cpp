#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int ans=0;
void dfs(int id,int step,int num){
    if(step==0){
        ans=max(num,ans);
        return;
    }
    for(int i=id+1;i<n;i++){
        dfs(i,step-1,num&a[i]);
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    dfs(-1,m,INT_MAX);
    cout<<ans;
    return 0;
}
