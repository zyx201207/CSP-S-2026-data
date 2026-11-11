#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
int n,d;
int vis[N][N];
int cnt[N][N];
vector<int>g[N];
int xp[N];
#define up(x) ((x)>0?(x):-(x))
void solve(){
    cin>>n>>d;
    memset(vis,-1,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++) cin>>xp[i];
    for(int i=0;i<n;i++){
        g[i].clear();
        for(int j=0;j<n;j++){
            if(i!=j&&abs(xp[i]-xp[j])<=d) g[i].push_back(j);
        }
    }
    for(int i=0;i<n;i++){
        queue<pair<int,int>>q;
        q.push({i,0});
        while(!q.empty()){
            int x=q.front().first,y=q.front().second;
            q.pop();
            for(auto c:g[x]){
                int now=y+1;
                if(now<vis[i][c]||vis[i][c]==-1){
                    vis[i][c]=now;
                    cnt[i][c]=1;
                    q.push({c,now});
                }
                else if(now==vis[i][c]) cnt[i][c]++;
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>=j) continue;
            if(vis[i][j]!=-1&&cnt[i][j]==2) ans++;
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}
