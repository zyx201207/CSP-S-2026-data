#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, t, n, d, a[5005], ans[5005][5005], vis[5005];
void bfs(int x)
{
    memset(vis, 0x3f, sizeof vis);
    queue<pair<int, int> > q; q.push({x, 0});while(!q.empty()){auto f=q.front();if(vis[f.first]==f.second)ans[x][f.first]++;if(vis[f.first]==0x3f3f3f3f)ans[x][f.first]++,vis[f.first]=f.second;q.pop();int p=f.first;while(a[p+1]-a[f.first]<=d){p++;q.push({p,f.second+1});}}}signed main(){ios::sync_with_stdio(0);cin.tie(0);freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);cin>>c>>t;while(t--){int tot=0;cin>>n>>d;memset(a,0x3f,sizeof a);memset(ans,0,sizeof ans);for(int i=1;i<=n;i++){cin>>a[i];}for(int i=1;i<=n;i++){bfs(i);}for(int i=1;i<n;i++){for(int j=i+1;j<=n;j++){if(ans[i][j]==2)tot++;}}cout<<tot<<"\n";}return 0;}