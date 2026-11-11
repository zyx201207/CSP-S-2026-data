#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<long long,long long>
using namespace std;
int c,t,n,k;
vector<int>ljb[15];
int dis[15];
bool vis[15];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0;i<n;i++){
            ljb[i].clear();
        }
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            ljb[u].pb(v);
            ljb[v].pb(u);
        }
        int ans=1<<30;
        for(int i=0;i<1<<n;i++){
            if(__builtin_popcount(i)==k){
                queue<int>q;
                memset(vis,0,sizeof(vis));
                memset(dis,0,sizeof(dis));
                for(int j=0;j<n;j++){
                    if(i>>j&1){
                        q.push(j);
                        vis[j]=1;
                    }
                }
                int qwq=0;
                int cnt=0;
                for(int j=0;j<n;j++){
                    if(i>>j&1){
                        for(int k=0;k<ljb[j].size();k++){
                            int t=ljb[j][k];
                            if(i>>t&1)cnt++;
                        }
                    }
                }
                cnt>>=1;
                cnt=k-cnt;
                if(cnt>2)continue;
                while(!q.empty()){
                    int wz=q.front();
                    q.pop();
                    for(int i=0;i<ljb[wz].size();i++){
                        int t=ljb[wz][i];
                        if(!vis[t]){
                            vis[t]=1;
                            dis[t]=dis[wz]+1;
                            q.push(t);
                        }
                    }
                }
                for(int i=0;i<n;i++){
                    qwq=max(qwq,dis[i]);
                }
                ans=min(ans,qwq);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
