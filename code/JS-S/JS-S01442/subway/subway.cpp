#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF=0x7f7f7f7f;
int c,n,m,d,q,T;
int w[500005];
map<int,int> t[500005];
map<int,int> td[500005];
int dis[500005];
bool vis[500005];

void precalc(){
    for(int s=1;s<n;s++){
        int mn=INF+1,mnid=-1;
        for(int i=s;i<=n;i++){
            dis[i]=(td[s][i]?td[s][i]:INF);
            if(dis[i]<mn) mn=dis[i],mnid=i;
        }
        vis[s]=1;
        for(int i=1;i<=n;i++){
            vis[mnid]=1;
            for(auto tmp:td[mnid]){
                int j=tmp.first,cost=tmp.second;
                if(!vis[j] && mn+cost<dis[j]){
                    dis[j]=mn+cost;
                }
            }
            mn=INF+1,mnid=1;
            for(int j=1;j<=n;j++) if(!vis[j] && dis[j]<mn) mn=dis[j],mnid=j;
        }
        for(int i=s+1;i<=n;i++){
            if(!td[s][i]) td[s][i]=td[i][s]=dis[i];
            else td[s][i]=td[i][s]=min(td[s][i],dis[i]);
        }
    }
}

ll solve(int s,int e){
    int ans=INF;
    for(auto sst:t[s]){
        int from=sst.first;
        for(auto est:t[e]){
            int to=est.first,cost=sst.second+est.second;
            ans=min(ans,cost+td[from][to]);
        }
    }
    return ans+w[s]+w[e];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        td[i][i]=0;
        for(int j=1;j<=k;j++){
            int st,tij;
            cin>>st>>tij;
            for(auto tmp:t[st]){
                int to=tmp.first,cost=tmp.second+tij;
                if(!td[i][to]) td[i][to]=td[to][i]=cost;
                else td[i][to]=td[to][i]=min(td[i][to],cost);
            }
            t[st][i]=tij;
        }
    }
    precalc();
    while(q--){
        int s,e;
        cin>>s>>e;
        cout<<solve(s,e)<<endl;
    }
    return 0;
}
