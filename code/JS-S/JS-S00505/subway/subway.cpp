#include<bits/stdc++.h>
using namespace std;
struct Pt{
    int vi,fl;
};
struct PPt{
    int u,mj;
};
int ccf,n,m,d,T;
int w[500010];
int a[510][50010],t[510][50010];
vector<Pt>v[50010];
int dis[500010];
int xr,yr;
queue<PPt>q;
void spfa(){
    q.push({xr,0});
    dis[xr]=0;
    while(!q.empty()){
        PPt top=q.front();
        q.pop();
        for(int i=0;i<v[top.u].size();i++){
            if(dis[v[top.u][i].vi]>top.mj+v[top.u][i].fl){
                dis[v[top.u][i].vi]=top.mj+v[top.u][i].fl;
                q.push({v[top.u][i].vi,top.mj+v[top.u][i].fl});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>ccf>>n>>m>>d>>T;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1,u;i<=n;i++){
        cin>>u;
        int jie=m+i;
        for(int j=1;j<=u;j++){
            cin>>a[i][j]>>t[i][j];
            v[jie].push_back({a[i][j],t[i][j]});
            v[a[i][j]].push_back({jie,t[i][j]});
        }
    }
    while(T--){
        cin>>xr>>yr;
        memset(dis,0x3f,sizeof(dis));
        spfa();
        cout<<dis[yr]+w[xr]+w[yr]<<endl;
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/