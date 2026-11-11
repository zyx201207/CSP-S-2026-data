//60pts
#include<bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
using pti = pair<int,pii>;
const int N=505,M=5e5+5;
int c,n,m,d,q;
int arr[M],dis[N][N];
int t[M][N];
set<int>st[N];
vector<int>in[M];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    fill(&dis[0][0],&dis[N][N],1e18);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>arr[i];
    for(int i=1;i<=n;i++){
        int sz;
        cin>>sz;
        for(int j=1;j<=sz;j++){
            int u,v;
            cin>>u>>v;t[u][i]=v;
            st[i].insert(u);
            in[u].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dis[i][j]!=1e18)continue;
            if(i==j){
                dis[i][j]=0;
                continue;
            }
            for(auto k=st[i].begin();k!=st[i].end();k++){
                if(st[j].find((*k))!=st[j].end()){
                    dis[i][j]=min(dis[i][j],t[(*k)][i]+t[(*k)][j]);
                    dis[j][i]=min(dis[j][i],t[(*k)][j]+t[(*k)][i]);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            for(int k=1;k<=n;k++){
                if(i==k||j==k)continue;
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int st,ed,ans=1e18;
        cin>>st>>ed;
        for(int j:in[st]){
            for(int k:in[ed]){
                //cout<<j<<" "<<k<<" "<<dis[j][k]<<" "<<arr[st]+t[st][j]+arr[ed]+t[ed][k]+dis[j][k]<<'\n';
                ans=min(ans,arr[st]+t[st][j]+arr[ed]+t[ed][k]+dis[j][k]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
