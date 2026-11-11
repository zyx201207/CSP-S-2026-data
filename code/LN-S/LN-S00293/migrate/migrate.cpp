#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> PLI;
const int N=2e6+10;
int n;
ll d,a[N],dist[N],cnt[N];
bool vis[N];
void dj(int s){
    priority_queue<PLI,vector<PLI>,greater<PLI>> q;
    fill(dist,dist+1+n,2e18);
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    q.push({0,s});
    dist[s]=0;
    vis[s]=1;
    while(q.size()){
        int t=q.top().second;
        q.pop();
        vis[t]=0;
        for(int i=1;i<=n;i++){
            ll l=abs(a[i]-a[t]);
            if(i==t||l>d) continue;
            if(dist[i]>dist[t]+1){
                dist[i]=dist[t]+1;
                cnt[i]=1;
                if(!vis[i]){
                    q.push({dist[i],i});
                    vis[i]=1;
                }
            }
            else if(dist[i]==dist[t]+1){
                cnt[i]++;
                q.push({dist[i],i});
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        ll ans=0;
        for(int i=1;i<=n;i++){
            dj(i);
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                if(cnt[j]==2) ans++;
            }
        }
        cout<<ans/2<<endl;
    }
    return 0;
}
