#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m;
const int N = 2e5+5;
int a[N],ans,vis[N];
void dfs(int cnt,int sum,int t){
    if(cnt==m){
        ans=max(ans,sum);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(t==1){
                sum=a[i];
            }
            vis[i]=1;
            dfs(cnt+1,sum&a[i],t+1);
            vis[i]=0;
        }
    }
    return ;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cout.tie(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,0,1);
    cout<<ans;
    return 0;
}
