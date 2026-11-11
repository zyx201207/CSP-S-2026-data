#include<bits/stdc++.h>
using namespace std;
#define int long long
#define to first 
#define cost second
#define MAXN 505
int c,n,m,d,q,dx,dy,w[MAXN],lic[MAXN][24];
vector<pair<int,int>> edge[MAXN];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k; cin>>k;
        if(k==2){
            int a,t,aa,tt; cin>>a>>t>>aa>>tt;
            edge[a].emplace_back(aa,t+tt);
            edge[aa].emplace_back(a,t+tt);
        }
        for(int j=1;j<=k;j++){
            int a,t; cin>>a>>t;
            lic[a][i]=t;
        }
    }
    for(int i=1;i<=q;i++){
        int f=1;
        cin>>dx>>dy;
        for(int j=0;j<edge[dx].size();j++){
            if(edge[dx][j].to==dy){
                cout<<w[dx]+w[dy]+edge[dx][j].cost<<"\n";
                f=0;
                break;
            }
            if(f){cout<<w[dx]+w[dy]<<"\n";}
        }
    }return 0;
}