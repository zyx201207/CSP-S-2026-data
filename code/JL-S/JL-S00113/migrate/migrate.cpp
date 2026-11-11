#include<bits/stdc++.h>
#define PII pair<int,int>
#define fi first
#define se second
#define int long long
using namespace std;
const int N=2e6+1;
int c,t,n,d,x[N],dis[N],cnt[N],vis[N];
vector<int>G[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        if(n==1){
            cout<<0<<'\n';
            continue;
        }
        if(c==11||c==12){
            int a=x[2]-x[1];
            int k=d/a;
            if(k==1||k==0){
                cout<<0<<'\n';
                continue;
            }
            cout<<max(0ll,n-(2*k-1))<<endl;
        }
        else{
            int ans=0;
            for(int i=1;i<=n;i++) G[i].clear();
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(x[j]-x[i]<=d){
                        G[i].push_back(j);
                    }
                }
            }
            for(int j=1;j<=n;j++){
                priority_queue<PII,vector<PII>,greater<PII>>q;
                memset(dis,0x3f,sizeof dis);
                memset(vis,0,sizeof vis);
                memset(cnt,0,sizeof cnt);
                dis[j]=0;
                cnt[j]=1;
                q.push({0,j});
                while(q.size()){
                    int u=q.top().se;
                    q.pop();
                    if(vis[u]) continue;
                    for(int i=0;i<G[u].size();i++){
                        int v=G[u][i];
                        //cout<<u<<" "<<v<<" "<<dis[u]<<" "<<dis[v]<<endl;
                        if(dis[v]>dis[u]+1){
                            dis[v]=dis[u]+1;
                            cnt[v]=cnt[u];
                            q.push({dis[v],v});
                        }
                        else if(dis[v]==dis[u]+1) cnt[v]+=cnt[u];
                    }
                }
                //for(int i=1;i<=n;i++) cout<<j<<" "<<i<<" "<<cnt[i]<<endl;
                for(int i=1;i<=n;i++) if(cnt[i]==2) ans++;
            }
            cout<<ans<<'\n';
        }
    }
}
