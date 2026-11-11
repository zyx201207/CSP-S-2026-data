#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> g[305];

void solve(){
    int n;ll d;cin>>n>>d;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if((ll)abs(a[i]-a[j])<=d)
        g[i].push_back(j),g[j].push_back(i);
    int ans=0;
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++){
        queue<int> q;
        vector<int> dist(n+1,-1);
        vector<int> cnt(n+1);
        q.push(i),dist[i]=0;
        while(q.size()){
            int x=q.front();q.pop();
            for(auto y:g[x]){
                if(dist[y]!=-1&&dist[y]!=dist[x]+1) continue;
                if(dist[y]==-1) dist[y]=dist[x]+1,q.push(y);
                else cnt[y]++;
            }
        }
        ans+=cnt[j]==1;
    }
    cout<<ans<<endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,tc;cin>>c>>tc;
    while(tc--) solve();
    return 0;
}
