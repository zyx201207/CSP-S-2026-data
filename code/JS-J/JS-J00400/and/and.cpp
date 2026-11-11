#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=-1e9;
int a[200010];
void dfs(int x,int sum,int cnt){
    if(cnt==m){
        ans=max(ans,sum);
        return;
    }
    if(x>n){
        return;
    }
    if(sum<ans){
        return;
    }
    if(m-cnt>n-x+1){
        return;
    }
    dfs(x+1,sum&a[x],cnt+1);
    dfs(x+1,sum,cnt);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0x7fffffff,0);
    cout<<ans;
    return 0;
}
