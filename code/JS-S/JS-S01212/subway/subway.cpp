#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e2+10;
const int M=5e5+10;
const ll INF=0x3f3f3f3f3f3f3f3f;
int Testid,n,m,d,q;
ll w[M];
int len[N];
int idx[N][M];
//unordered_map<int,int>idx[N];
vector<int>a[N],t[N],st[M];
ll dis[N][N];
int main(){
    //freopen("/home/user/Desktop/subway/subway6.in","r",stdin);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0)->sync_with_stdio(false);
    cin>>Testid>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>len[i];
        a[i].resize(len[i]+1);
        t[i].resize(len[i]+1);
        for(int j=1;j<=len[i];j++){
            cin>>a[i][j]>>t[i][j];
            idx[i][a[i][j]]=j;
            st[a[i][j]].push_back(i);
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++){
       // cout<<st[i].size()<<"\n";
        for(auto x:st[i]){
            for(auto y:st[i]){
                if(x==y)continue;
                ll w=t[x][idx[x][i]]+t[y][idx[y][i]];
                //cout<<x<<" "<<y<<" "<<w<<"\n";
                dis[x][y]=min(dis[x][y],w);
                dis[y][x]=min(dis[x][y],w);
            }
        }
    }
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(dis[i][k]==INF)continue;
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int s,tt;
        ll ans=INF;
        cin>>s>>tt;
        for(auto x:st[s]){
            for(auto y:st[tt]){
                //cout<<s<<" "<<tt<<" "<<x<<" "<<y<<" "<<dis[x][y]<<" "<<t[x][idx[x][s]]<<" "<<t[y][idx[y][tt]]<<"\n";
                ans=min(ans,dis[x][y]+t[x][idx[x][s]]+t[y][idx[y][tt]]);
            }
        }
        cout<<ans+w[s]+w[tt]<<"\n";
    }
    return 0;
}
