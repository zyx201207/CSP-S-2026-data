#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll C,T,n,d,a[2000005],dis[2000005],cnt[2000005];
vector<int> g[2000005];
queue<pair<int,int> >di,q;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>C>>T;
    while(T--){
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i],g[i].clear();
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d) g[i].push_back(j);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) dis[j]=2e9,cnt[j]=0;
            di.push({i,0});
            while(!di.empty()){
                pair<int,int> t=di.front();
                di.pop();
                int u=t.first,w=t.second;
                for(int v:g[u]){
                    if(dis[v]>w+1){
                        dis[v]=w+1;
                        di.push({v,dis[v]});
                    }
                }
            }
            q.push({i,0});
            while(!q.empty()){
                pair<int,int> t=q.front();
                q.pop();
                int u=t.first,w=t.second;
                if(w>dis[u]) continue;
                //cout<<u<<'\n';
                for(int v:g[u]){
                    if(w+1==dis[v]) cnt[v]++;
                    q.push({v,w+1});
                }
            }
            for(int i=1;i<=n;i++){
                if(cnt[i]==2) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
//diff -ZB migrate.out migrate.ans
