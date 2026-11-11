#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2e6+5;
int c,T,n,d;
int a[N],dis[N],cnt[N];
bool vis[N];
vector<int> g[N];
void dij(int s){
    queue<pii> q;  //first: node id, second: distance
    for(int i=1;i<=n;i++){
        dis[i]=0x3f3f3f3f3f3f3f3f;
        cnt[i]=0;
        vis[i]=false;
    }
    dis[s]=0;
    cnt[s]=1;
    q.push({s,0});
    while(!q.empty()){
        pii u=q.front();
        q.pop();
        int x=u.fi;
        if(vis[x])  continue;
        vis[x]=true;
        for(auto y:g[x]){
            if(dis[x]+1<dis[y]){
                dis[y]=dis[x]+1;
                cnt[y]=cnt[x];
                q.push({y,dis[y]});
            }
            else  if(dis[x]+1==dis[y])  cnt[y]+=cnt[x];
        }
    }
}
void sit(){
    int dif,cnt;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)  cin>>a[i];
        if(n==1){
            cout<<"0\n";
            continue;
        }
        dif=a[2]-a[1];
        cnt=d/dif;
        if(cnt<=1){
            cout<<"0\n";
            continue;
        }
        cnt=cnt*2-1;
        cout<<max(0ll,n-cnt)<<"\n";
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    if(c==11||c==12){
        sit();
        return 0;
    }
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            g[i].clear();
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        dij(1);
        int ans=0;
        for(int i=1;i<=n;i++){
            dij(i);
            for(int j=i+1;j<=n;j++){
                if(cnt[j]==2)  ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
