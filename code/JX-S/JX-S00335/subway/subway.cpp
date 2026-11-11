#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int dist[510][510];
struct node{
    int a,t;
};
vector<node> a[500010];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    memset(dist,0x3f3f3f3f3f3f3f3f,sizeof(dist));
    vector<int> w(m+1);
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        dist[i][i]=0;
    } 
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int A,t;
            cin>>A>>t;
            a[A].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<a[i].size();j++){
            for(int k=j+1;k<a[i].size();k++){
                dist[a[i][j].a][a[i][k].a]=min(dist[a[i][j].a][a[i][k].a],a[i][j].t+a[i][k].t);
                dist[a[i][k].a][a[i][j].a]=dist[a[i][j].a][a[i][k].a];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
            }
        }
    }
    while(q--){
        int x,y,ans=0x3f3f3f3f3f3f3f3f;
        cin>>x>>y;
        for(int i=0;i<a[x].size();i++){
            for(int j=0;j<a[y].size();j++){
                ans=min(ans,dist[a[x][i].a][a[y][j].a]+a[x][i].t+a[y][j].t);
            }
        }
        ans+=w[x]+w[y];
        cout<<ans<<"\n";
    }
    return 0;
}
