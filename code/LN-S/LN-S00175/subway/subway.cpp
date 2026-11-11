#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int c,n,m,d,q;
int w[N];
int a[505][505];
int t[N][505];
struct node{
    int u,v,w;
};
vector<node>g[N];
int s[N][N];
queue<int>p;
void dijkstar(int x){
    for(int i=1;i<=m;i++)s[x][i]=1e9;
    s[x][x]=0;
    p.push(x);
    while(!p.empty()){
        int d=p.front();
        p.pop();
        for(auto i:g[d]){
            int u=i.u,v=i.v,w=i.w;
            if(s[x][v]>=s[x][u]+w){
                s[x][v]=s[x][u]+w;
                p.push(v);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)scanf("%d",&w[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i][0]);
        for(int j=1;j<=a[i][0];j++){
            scanf("%d",&a[i][j]);
            scanf("%d",&t[a[i][j]][i]);
        }
        for(int j=1;j<=a[i][0];j++){
            for(int k=1;k<=a[i][0];k++){
                if(j==k)continue;
                g[a[i][j]].push_back({a[i][j],a[i][k],t[a[i][j]][i]+t[a[i][k]][i]});
            }
        }
    }
    for(int i=1;i<=m;i++){
        dijkstar(i);
    }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        cout<<w[x]+w[y]+s[x][y]<<endl;
    }
    return 0;
}
