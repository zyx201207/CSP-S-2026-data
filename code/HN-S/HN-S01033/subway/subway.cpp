#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 514;
const int maxm = 5e5+114;
int w[maxm];
vector< array<int,2> > sp[maxm];
int f[maxn][maxn];
const int inf = 1e18+114;
int c,n,m,d,q;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j) f[i][j]=inf;
        }
    }
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            sp[a].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(int p=0;p<(int)sp[i].size();p++){
            for(int q=0;q<p;q++){
                f[sp[i][p][0]][sp[i][q][0]]=min(f[sp[i][p][0]][sp[i][q][0]],sp[i][p][1]+sp[i][q][1]);
                f[sp[i][q][0]][sp[i][p][0]]=min(f[sp[i][q][0]][sp[i][p][0]],sp[i][p][1]+sp[i][q][1]);
            }
        }
    }
    for(int z=1;z<=n;z++){
        for(int x=1;x<=n;x++){
            for(int y=1;y<=n;y++) f[x][y]=min(f[x][y],f[x][z]+f[y][z]);
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=inf;
        for(int p=0;p<(int)sp[x].size();p++){
            for(int q=0;q<(int)sp[y].size();q++) ans=min(ans,sp[x][p][1]+sp[y][q][1]+f[sp[x][p][0]][sp[y][q][0]]);
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}
/*
0 2 5 20 1
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 2
*/