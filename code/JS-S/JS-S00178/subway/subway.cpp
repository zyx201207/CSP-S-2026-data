#include <bits/stdc++.h>
#define ll long long
#define pli pair<ll,ll>

using namespace std;

int c,n,m,d,q;
const int N=1e5+10;
int w[N*5];
vector<pli> g[550];
int k[550];

ll flo[3010][3010];

void solve1(){
    memset(flo,0x3f,sizeof(flo));

    for(int i=1;i<=m;i++){
        for(int j=0;j<k[i];j++){
            int v=g[i][j].second;
            ll w=g[i][j].first;
            flo[i][v]=min(w,flo[i][v]);
            flo[v][i]=min(w,flo[v][i]);
        }
    }


    for(int i=1;i<=m;i++){
        flo[i][i]=0;
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                flo[i][j]=min(flo[i][j],flo[i][k]+flo[k][j]);
            }
        }
    }

    while(q--){
        int x,y;
        cin>>x>>y;

        cout<<flo[x][y]+w[x]+w[y]<<'\n';
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>c>>n>>m>>d>>q;

    for(int i=1;i<=m;i++){
        cin>>w[i];
    }

    int maxk=0;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        maxk=max(k[i],maxk);
        vector<pli> tt;
        for(int j=1;j<=k[i];j++){
            ll v,t;
            cin>>v>>t;
            tt.push_back({t,v});
            tt.push_back({t,i});
        }
        for(int x=0;x<tt.size();x++){
            int u=tt[x].second;
            for(int y=0;y<=tt.size();y++){
                ll v=tt[y].second;
                ll w=tt[y].first;

                g[u].push_back({w,v});
                g[v].push_back({w,u});
            }
        }
    }

    if(m<=3000){
        solve1();
    }

    return 0;
}
