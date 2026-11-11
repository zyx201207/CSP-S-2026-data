#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,a[N];
int ans=0;
inline void dfs(int pos,int now,int cnt,int s){
   if(pos==m||s==n){
        if(pos==m) ans=max(ans,cnt);
        return;
   }
   dfs(pos,now,cnt,s+1);
   for(int i=now+1;i<=n;i++){
        if(s==0) dfs(pos+1,i,a[i],s+1);
        else dfs(pos+1,i,cnt&a[i],s+1);
   }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(0,0,0,0);
    cout<<ans;
    return 0;
}
