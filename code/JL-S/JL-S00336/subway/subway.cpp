#include<bits/stdc++.h>
using namespace std;
const int N=505;
long long w[N],t[N][N],a[N][N],dis[N];
int c,m,n,dd,q;
bool v[N];
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> d[N];
void dij(int x,long long l){
    if(v[x]) return;
    v[x]=1;
    if(x==1) {
        if(dis[1]==0) return;
        dis[1]==0;
    }
    while(!d[x].empty()){
        int y=d[x].top().second,k=d[x].top().first;
        if(dis[y]<0||dis[y]>=k+l){
            dis[y]=k+l;
            dij(y,k+l);
        }
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>dd>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        dis[i]=-1;
    }
    for(int i=1;i<=n;i++){
        int ki;
        cin>>ki;
        for(int j=1;j<=ki;j++){
            cin>>a[i][j]>>t[i][j];
        }
        for(int j=1;j<=ki;j++){
            for(int k=1;k<=ki;k++){
                if(j==k) continue;
                int jj=a[i][j],kk=a[i][k];
                d[jj].push({t[i][jj],kk});
                d[kk].push({t[i][kk],jj});
            }
        }
    }
    for(int i=1;i<=m;i++){
        while(!d[i].empty()){
            d[i].pop();
        }
    }
    dij(1,0);
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]+abs(dis[x]-dis[y])<<"\n";
    }
    return 0;
}

