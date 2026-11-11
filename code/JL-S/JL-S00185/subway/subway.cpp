#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=5e5+5,M=505;
int c,n,m,d,q,len[M];
int w[N],ds[M][M];
bool vis[N];
vector<PII> sub[N];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    memset(ds,0x3f,sizeof ds);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        ds[i][i]=0;
        cin>>len[i];
        for(int j=1;j<=len[i];j++){
            int x,y;
            cin>>x>>y;
            sub[x].push_back({i,y});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<sub[i].size();j++){
            int x=sub[i][j].first,w1=sub[i][j].second;
            for(int k=0;k<sub[i].size();k++){
                int y=sub[i][k].first,w2=sub[i][k].second;
                if(x==y)continue;
                ds[y][x]=ds[x][y]=min(ds[x][y],w1+w2);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ds[j][i]=ds[i][j]=min(ds[i][k]+ds[k][j],ds[i][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int st,ed,ans=1e16;
        cin>>st>>ed;
        for(int f1=0;f1<sub[st].size();f1++){
            for(int f2=0;f2<sub[ed].size();f2++){
                int x=sub[st][f1].first,y=sub[ed][f2].first;
                int w1=sub[st][f1].second,w2=sub[ed][f2].second;
                ans=min(ans,w1+w2+ds[x][y]);
            }
        }
        cout<<ans+w[st]+w[ed]<<"\n";
    }
    return 0;
}
