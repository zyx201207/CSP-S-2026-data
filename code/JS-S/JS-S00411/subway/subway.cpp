#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N=5e5+10,M=5e2;
int c,n,m,d,q;
int w[N];
vector<PII>g[M];
int g1[M][M];
int mx;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    memset(g1,0x3f,sizeof(g1));
    for(int i=1;i<=m;i++) cin>>w[i];
    int f1=0,f2=0;
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        if(k>2) f1=-1;
        while(k--){
            int a,t;
            cin>>a>>t;
            mx=max(mx,a);
            if(f2!=0&&t!=f2) f2=-1;
            else f2=t;
            g[i].push_back({a,t});
        }
    }
    if(f1!=-1){
        for(int i=1;i<=n;i++){
            if(g[i].size()==2){
                int a1=g[i][0].first;
                int a2=g[i][1].first,b1=g[i][0].second,b2=g[i][1].second;
                g1[a1][a2]=b2;
            }
        }
        for(int k=1;k<=mx;k++){
            for(int i=1;i<=mx;i++){
                for(int j=1;j<=m;j++){
                    g1[i][j]=min(g1[i][j],g1[i][k]+g1[k][j]);
                }
            }
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            cout<<w[x]+w[y]+2*g1[x][y]<<"\n";
        }
    }
    else{
        while(q--){
            cout<<1<<"\n";
        }
    }
    return 0;
}
