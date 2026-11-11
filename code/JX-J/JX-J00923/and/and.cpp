#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m,ans;
int a[N];
void dfs(int i,int k,int oans){
    if(k==m){
        ans=max(ans,oans);
        return ;
    }
    if(i>n){
        return ;
    }
    if(!oans)
        dfs(i+1,k+1,a[i]);
    else dfs(i+1,k+1,oans&a[i]);
    dfs(i+1,k,oans);
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
