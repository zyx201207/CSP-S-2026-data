# include <bits/stdc++.h>
using namespace std;
const int MAXN=2*1e5
int n,m;
int ans=-1;
int a[MAXN];
void dfs(int pos,int andh,int cnt){
    if(cnt>m){
        ans=max(ans,andh);
        return;
    }
    for(int i=pos+1;i<=n;i++) dfs(i,a[i]&a[pos],cnt+1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1,a[1],1);
    cout<<ans;
}
