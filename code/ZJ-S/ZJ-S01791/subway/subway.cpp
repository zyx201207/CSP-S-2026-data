#include<bits/stdc++.h>
#define int long long
#define For(i,l,r) for(int i=(l);i<=(r);i++)
#define inf (int)(1e18)
using namespace std;
inline int rd(){
    int x=0,f=0;char c=getchar();
    while(!isdigit(c)) f=(c=='-'),c=getchar();
    while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return f?-x:x;
}
const int N=510,M=5e5+10;
int c,n,m,d,q,dis[N][N],w[M],k[N];
vector<pair<int,int> >id[M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=rd(),n=rd(),m=rd(),d=rd(),q=rd();
    For(i,1,m) w[i]=rd();
    For(i,1,n){
        k[i]=rd();
        For(j,1,k[i]){
            int x=rd(),v=rd();
            id[x].push_back(make_pair(i,v));
        }
        For(j,1,n) dis[i][j]=inf;
        dis[i][i]=0;
    }
    For(x,1,m){
        for(int i=0;i<(int)id[x].size();i++){
            int y=id[x][i].first;
            for(int j=0;j<(int)id[x].size();j++){
                int z=id[x][j].first;
                dis[y][z]=min(dis[y][z],id[x][i].second+id[x][j].second);
            }
        }
    }
    For(k,1,n) For(i,1,n){
        if(i==k) continue;
        For(j,1,n){
            if(i==j||j==k) continue;
            dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
    while(q--){
        int x=rd(),y=rd();
        int ans=inf;
        for(int i=0;i<(int)id[x].size();i++){
            int x_=id[x][i].first;
            for(int j=0;j<(int)id[y].size();j++){
                int y_=id[y][j].first;
                ans=min(ans,dis[x_][y_]+id[x][i].second+id[y][j].second);
            }
        }
        printf("%lld\n",ans+w[x]+w[y]);
    }
}