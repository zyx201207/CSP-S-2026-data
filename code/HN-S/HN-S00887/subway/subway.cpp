#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
const int N=5e5+10,M=520,inf=1e9;
//地铁站数，地铁线数
int n,m,c,d,q,a[N],k[M],dis[M][M];
struct node{
    vector<pair<int,int> > xian;
}dian[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            dis[i][j]=inf;
        }
        dis[i][i]=0;
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int x,y;
            cin>>x>>y;
            dian[x].xian.push_back({i,y});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<dian[i].xian.size();j++){
            for(int k=0;k<dian[i].xian.size();k++){
                // if(j==k) continue;
                pair<int,int> x,y;
                x=dian[i].xian[j];y=dian[i].xian[k];
                dis[x.fi][y.fi]=min(dis[x.fi][y.fi],x.se+y.se);
                dis[y.fi][x.fi]=min(dis[y.fi][x.fi],x.se+y.se);
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            // if(k==i) continue;
            for(int j=1;j<=m;j++){
                if(i==j) continue;
                // if(k==j||i==j) continue;
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=inf;
        for(int i=0;i<dian[x].xian.size();i++){
            for(int j=0;j<dian[y].xian.size();j++){
                int kou=dian[x].xian[i].fi;
                int gay=dian[y].xian[j].fi;
                int val=dis[kou][gay]+dian[x].xian[i].se+dian[y].xian[j].se;
                ans=min(ans,val);
            }
        }
        cout<<ans+a[x]+a[y]<<endl;
    }
    return 0;
}
/*
g++ -o a subway.cpp -std=c++14 -O2
time ./a
*/
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/