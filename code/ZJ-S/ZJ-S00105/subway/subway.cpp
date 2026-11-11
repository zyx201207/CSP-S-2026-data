#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mkp make_pair
using namespace std;
const int N=510;
inline void mmn(int &x,int y){
	if(y<x)x=y;
	return;
}
void solve(){
    int c,n,m,d,q;
    /*
    c testnumber
    n number of line
    m number of stations
    d the max cnt of lines in a station
    q 
    */
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    vector<int>w(m+2,0);//%lld
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }           
    vector<vector<int> >dis(n+2,vector<int>(n+2,1e18));
    vector<vector<pii> >pastLine(m+2,vector<pii>(0));
    for(int i=1;i<=n;i++){
        int k;
        scanf("%lld",&k);
        for(int j=1;j<=k;j++){
            int x,y;
            scanf("%lld%lld",&x,&y);
            pastLine[x].push_back(mkp(i,y));
        }
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        int len=pastLine[i].size();
        for(int j=0;j<len;j++){
            for(int k=j+1;k<len;k++){
                mmn(
                dis[pastLine[i][j].first][pastLine[i][k].first]
                ,pastLine[i][j].second+pastLine[i][k].second
                );
                mmn(
                dis[pastLine[i][k].first][pastLine[i][j].first]
                ,pastLine[i][j].second+pastLine[i][k].second
                );

            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)if(k!=i&&i!=j&&k!=j){
                if(dis[i][k]==1e18||dis[k][j]==1e18)continue;
                if(dis[i][k]+dis[k][j]<dis[i][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
    while(q--){
        int s,t;
        scanf("%lld%lld",&s,&t);
        int lens=pastLine[s].size();
        int lent=pastLine[t].size();
        int ans=1e18;
        for(int i=0;i<lens;i++){
            for(int j=0;j<lent;j++){
                int xs,ys,xt,yt;
                tie(xs,ys)=pastLine[s][i];
                tie(xt,yt)=pastLine[t][j];
                if(dis[xs][xt]==1e18)continue;
                mmn(ans,dis[xs][xt]+ys+yt+w[s]+w[t]);
            }
        }
        printf("%lld\n",ans);
    }
    return;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    solve();
    return 0;
}
